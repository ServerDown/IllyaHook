#ifndef ILLYA_CONSOLE_H
#define ILLYA_CONSOLE_H

#include "Includes.h"
#include <time.h>

class cConsole {
public:
	void OpenConsole();
	void CloseConsole();
	void Log(const char *msg, ...);

	std::string GetTime();
};

#endif
