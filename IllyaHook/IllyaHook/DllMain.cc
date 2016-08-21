/* PROJECT IllyaHook by MRX - KUNO [ started : 20-08-16 ] */

#include "Common.h"
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
		// Note, NULL is not guaranteed to be 0. It can be 0L. Nullptr will always favor the pointer version. 
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)CheatThread, nullptr, 0, nullptr);  
	}
	return TRUE;
}
