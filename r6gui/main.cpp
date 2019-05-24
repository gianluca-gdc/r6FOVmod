//#include <iostream>	
//#include <Windows.h>
//#include <vector>
//#include "proc.h"
//
//int main()
//{
//	//Get ProcId of the target process
//	DWORD procId = GetProcId(L"RainbowSix.exe");
//
//	//GetmoduleBaseaddress
//	uintptr_t moduleBase = GetModuleBaseAddress(procId, L"RainbowSix.exe");
//	std::cout << moduleBase << std::endl;
//	//Get HANDLE to process
//	HANDLE hProcess = 0;
//	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
//
//	//RainbowSix.exe + GAMEMANAGER ] + 0x1F8 ] + 0xD8 ] + 0x28 ]+ 0x138 ] + 0x120] + 0x0] + 0x40
//	//Resolve base address of the pointer chain
//	uintptr_t dynamicPtrBaseAddr = moduleBase + 0x4E92358;
//
//	std::cout << "Dynamic Pointer Base Address = " << "0x" << std::hex << dynamicPtrBaseAddr << std::endl;
//
//	//Resolve our damage modifier pointer chain
//	std::vector<unsigned int> damageOffsets = { 0x1F8 , 0xD8 , 0x28 , 0x138 , 0x120 , 0x0 , 0x40 };
//	uintptr_t damageAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, damageOffsets);
//
//	std::cout << "Damage address = " << "0x" << std::hex << damageAddr << std::endl;
//
//	//Read damage value
//	int damageValue = 0;
//
//	ReadProcessMemory(hProcess, (BYTE*)damageAddr, &damageValue, sizeof(damageValue), nullptr);
//	std::cout << "current Damage = " << std::dec << damageValue << std::endl;
//
//	//Write to it
//	int newDamage = 8;
//	WriteProcessMemory(hProcess, (BYTE*)damageAddr, &newDamage, sizeof(newDamage), nullptr);
//
//	//read out again
//	ReadProcessMemory(hProcess, (BYTE*)damageAddr, &damageValue, sizeof(damageValue), nullptr);
//
//	std::cout << "New Damage = " << std::hex << damageValue << std::endl;
//	std::cin.get();
//	return 0;
//} 