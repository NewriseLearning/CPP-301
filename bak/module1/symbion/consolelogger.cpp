//	consolelogger.cppp

#include "symbion.h"

//extern "C" {
//#include <stdio.h>
//}

#include <cstdio>	// c++ header for stdio.h
#include <cstring>	// C++ header for string.h (strlen)
#include <exception>

namespace symbion {

	CConsoleLogger::CConsoleLogger() : CBaseLogger("CConsoleLogger") { }
	CConsoleLogger::CConsoleLogger(const char* source) : CBaseLogger(source) { }

	void CConsoleLogger::Write(const char* message, LogType logType) const {
		printf("[%s] %s(\"%s\")\n", Source, GetLogTypeText(logType), message);
	}
}
