#include "symbion.h"
#include <cstdio>

namespace symbion {
	CConsoleLogger::CConsoleLogger() : CBaseLogger("CConsoleLogger") { }

	CConsoleLogger::CConsoleLogger(const char* source) : CBaseLogger(source) { }

	void CConsoleLogger::Write(const char* message, LogType logType) const {
		printf("[%s] %s(\"%s\")\n", Source, GetLogTypeText(logType), message);
	}
}
