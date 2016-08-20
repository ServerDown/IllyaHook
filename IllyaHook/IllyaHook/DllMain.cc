/* PROJECT IllyaHook by MRX - KUNO [ started : 20-08-16 ] */
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Includes.h"
#include "Console.h"
#include "InterfacesGrabber.h"
#include "Interfaces.h"
#include "SDK.h"


Interfaces* interfaces = nullptr;



HINSTANCE ThisModule;
cConsole *Console;
 

void CheatThread(LPVOID params)
{
	/*grab interfaces here*/
	interfaces = new Interfaces();
 

	// startup // 
 
	Console->OpenConsole();
 	Console->Log("Build date: %s", __DATE__);
	Console->Log("Project: Illyahook");
}

DWORD WINAPI DllMain(HINSTANCE inst, DWORD reason, LPVOID reserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		ThisModule = inst;
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)CheatThread, NULL, NULL, NULL);
	}
	return TRUE;
}
