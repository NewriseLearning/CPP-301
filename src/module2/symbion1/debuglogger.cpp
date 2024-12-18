//	debuglogger.cpp

// #define _CRT_SECURE_NO_WARNINGS

#include "pch.h"

namespace symbion {
	CDebugLogger::CDebugLogger() : CBaseLogger("CDebugLogger") { }
	CDebugLogger::CDebugLogger(const char* source) : CBaseLogger(source) { }

	void CDebugLogger::Write(const char* message, LogType logType) const {
		char text[1024];
		//sprintf(text, "[%s] %s(\"%s\")\n",
		//	Source, GetLogTypeText(logType), message);
		sprintf_s(text, "[%s] %s(\"%s\")\n",
			Source, GetLogTypeText(logType), message);
		OutputDebugStringA(text);
	}
}

