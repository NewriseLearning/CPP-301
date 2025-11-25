#include "symbion.h"
#include <cstring>
#include <windows.h>

namespace symbion {
	CBaseLogger* CLoggerFactory::CreateInstance() {
		char buffer[256];
		if (GetEnvironmentVariableA("LOGGER", buffer, sizeof(buffer)) > 0) {
			_strupr_s(buffer);
			if (strcmp(buffer, "CONSOLE") == 0) return new CConsoleLogger();
			if (strcmp(buffer, "FILE") == 0) return new CFileLogger();
			if (strcmp(buffer, "DEBUG") == 0) return new CDebugLogger();
		}
		return new CConsoleLogger(); // default
	}
}
