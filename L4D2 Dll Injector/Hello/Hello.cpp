// Hello.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

// This DLL only loads the HPatch.dll
// This is to prevent L4D2 trying to invoke an export to this dll.

VOID OnAttachProcess() {
	LoadLibraryA("HPatch.dll"); 
}

// This is the main entry point to your xex file.
BOOL WINAPI DllMain(HANDLE hInst, DWORD dwReason, LPVOID lpReserved) {
	if (dwReason == DLL_PROCESS_ATTACH) {
		OnAttachProcess();

		// Instantly cause an unload.
		((PLDR_DATA_TABLE_ENTRY)hInst)->LoadCount = 1;
		return FALSE;
	}

	return TRUE;
} 