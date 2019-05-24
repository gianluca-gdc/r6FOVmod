#pragma once
#include <iostream>
#include <Windows.h>
#include <cmath>
#include "proc.h"
#include "Offsets.h"

using namespace std;
static HANDLE hProcess = 0;
static uintptr_t moduleBase = 0;
void initProc() {
	//Get ProcId of the target process
	DWORD procId = GetProcId(L"RainbowSix.exe");
	
	//GetmoduleBaseaddress
	moduleBase = GetModuleBaseAddress(procId, L"RainbowSix.exe");
	//Get HANDLE to process
	
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
	
}
static int convertFromFovRaw(int rawFov) {
	double fovWhen90 = 1070141403;
	double fovWhen60 = 1065749138;
	double slope = ((double)90 - (double)60)/(fovWhen90 - fovWhen60);
	double yInt = 90 - slope * fovWhen90;
	double convertedFov = slope * rawFov + yInt;
	return round(convertedFov);
}
int readFovValue() {
	
	//RainbowSix.exe + 0x4E94398 + 0x28] + 0x0] + 0x38]
	//Resolve base address of the pointer chain
	uintptr_t dynamicPtrBaseAddr = moduleBase + DYNAMIC_BASE_PTR_OFFSET;

	//Resolve our damage modifier pointer chain
	std::vector<unsigned int> damageOffsets = { POINTER_1 , POINTER_2 , POINTER_3 };
	uintptr_t damageAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, damageOffsets);

	//Read damage value
	int rawFov = 0;

	ReadProcessMemory(hProcess, (BYTE*)damageAddr, &rawFov, sizeof(rawFov), nullptr);
	
	return convertFromFovRaw(rawFov);
}
static int convertToRawFov(int actualFov) {
	int fovWhen90 = 1070141403;
	int fovWhen60 = 1065749138;
	int slope = (fovWhen90 - fovWhen60) / (90 - 60);
	int yInt = fovWhen90 - slope * 90;
	int convertedFov = slope * actualFov + yInt;
	return convertedFov;
}
void writeFovValue(int newFovValue) {
	int rawFovValue = convertToRawFov(newFovValue);
	//RainbowSix.exe + 0x4E94398 + 0x28] + 0x0] + 0x3C]
	//Resolve base address of the pointer chain
	uintptr_t dynamicPtrBaseAddr = moduleBase + DYNAMIC_BASE_PTR_OFFSET;

	//Resolve our damage modifier pointer chain
	std::vector<unsigned int> damageOffsets = { POINTER_1 , POINTER_2 , POINTER_3 };
	uintptr_t damageAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, damageOffsets);

	//Write to it
	WriteProcessMemory(hProcess, (BYTE*)damageAddr, &rawFovValue, sizeof(rawFovValue), nullptr);
}
