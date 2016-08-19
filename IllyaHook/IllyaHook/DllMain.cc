/* PROJECT IllyaHook by MRX - KUNO [ started : 20-08-16 ] */

#include <Windows.h>
#include <iostream>

using namespace std;

DWORD WINAPI InterfaceInit(LPVOID IpThreadParam)
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << __DATE__ << endl;
	cout << "-IllyaHook by MRX & Kuno" << endl;
	return 1;
}


BOOL WINAPI DllMain(HINSTANCE pInstance, DWORD dwReason, LPVOID IpReversed)
{
	if (dwReason != DLL_PROCESS_ATTACH)
		return TRUE;
	CreateThread(nullptr, NULL, InterfaceInit, nullptr, NULL, nullptr);
	return TRUE;
}