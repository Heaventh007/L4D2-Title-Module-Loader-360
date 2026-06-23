// Hello.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

VOID OnAttachProcess() {
	DbgPrint("Hello from HPatch.dll!\n");

	// From here on, you can setup your hooks and whatever else.
}

VOID OnDetachProcess() {

}

// This is the main entry point to your xex file.
BOOL WINAPI DllMain(HANDLE hInst, DWORD dwReason, LPVOID lpReserved) {
	if (dwReason == DLL_PROCESS_ATTACH) OnAttachProcess();
	if (dwReason == DLL_PROCESS_DETACH) OnDetachProcess();

	return TRUE;
} 