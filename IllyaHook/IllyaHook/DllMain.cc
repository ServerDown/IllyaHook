/* PROJECT IllyaHook by MRX - KUNO [ started : 20-08-16 ] */

#include "Includes.h"
#include "Console.h"

HINSTANCE ThisModule;
cConsole *Console;

void CheatThread(LPVOID params)
{
	Beep(1000, 1);
	Console->OpenConsole();
	Console->Log("Build date: %s", __DATE__);
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
