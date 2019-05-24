#include <iostream>
#include <chrono>

#include <thread>
#include "MyForm.h"
#include "Yeet.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace r6gui;
using namespace System::Threading;

ref struct Globals {
	static MyForm^ globalForm;
};

void checkFovThread();
bool guiExited = false;

[STAThreadAttribute]
int main() {
	initProc();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	
	Globals::globalForm = gcnew MyForm;
	MyForm^ formPtr = Globals::globalForm;

	std::thread t1(checkFovThread);
	Application::Run(formPtr);
	guiExited = true;
	t1.join();

	return 0;
}

static void checkFovThread() {
	MyForm^ formPtr = Globals::globalForm;
	int previousValue = 0;

	while (!guiExited) {
		if (formPtr->IsHandleCreated) {
			int currentValue = readFovValue();
			if (currentValue != previousValue) {
				String^ stringInt = intToString(currentValue);
				formPtr->Invoke(formPtr->myDelegate, stringInt);
				previousValue = currentValue;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
