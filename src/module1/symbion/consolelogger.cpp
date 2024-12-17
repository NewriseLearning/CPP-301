//	consolelogger.cppp

#include "symbion.h"

//extern "C" {
//#include <stdio.h>
//}

#include <cstdio>	// c++ header for stdio.h

namespace symbion {

	const char* CConsoleLogger::GetSource() { return m_source; }

	void CConsoleLogger::PutSource(const char* source) {
		m_source = source;
	}

	void CConsoleLogger::Write(const char* message, LogType logType) {
		switch (logType) {
			case LogType::Information: printf("[%s] Information(\"%s\")\n", m_source, message); break;
			case LogType::Warning: printf("[%s] Warning(\"%s\")\n", m_source, message); break;
			case LogType::Error: printf("[%s] Error(\"%s\")\n", m_source, message); break;
		}
	}

}
