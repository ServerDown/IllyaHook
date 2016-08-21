// Copyright (C) 2016 Mrx

#ifndef ILLYA_CONSOLE_H
#define ILLYA_CONSOLE_H

#include "Common.h"

class cConsole {
public:
	void OpenConsole();
	void CloseConsole();
	void Log(const char *msg, ...);

	std::string GetTime();
};

#endif // ILLYA_CONSOLE_H
