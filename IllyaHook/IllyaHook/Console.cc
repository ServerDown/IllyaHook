// Copyright (C) 2016 Mrx

#include "Console.h"

void cConsole::OpenConsole()
{
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	SetConsoleTitle(L"IllyaHook for Counter-Strike: Global Offensive"); // maybe add random text generator for title
}

void cConsole::CloseConsole()
{
	FreeConsole();
}
 
void cConsole::Log(const char * msg, ...)
{
	if (!msg)
		return;

	va_list list;
	char buffer[256] = {0};

	va_start(list, msg);
	_vsnprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), msg, list);
	va_end(list);

	if (buffer[0] != '\0')
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("[%s] ", GetTime().c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("%s\n", buffer);
	}
}

std::string cConsole::GetTime()
{
	time_t currenttime;
	struct tm* timeinfo;
	static char timestring[10];

	time(&currenttime);
	timeinfo = localtime(&currenttime);

	strftime(timestring, sizeof(timestring), "%I:%M%p", timeinfo);
	return timestring;
}
