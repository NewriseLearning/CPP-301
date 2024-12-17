//	consolelogger.cppp

#include "symbion.h"

//extern "C" {
//#include <stdio.h>
//}

#include <cstdio>	// c++ header for stdio.h
#include <cstring>	// C++ header for string.h (strlen)
#include <exception>

namespace symbion {

	CConsoleLogger::CConsoleLogger() : m_source(nullptr) {
		PutSource("CConsoleLogger");
	}

	CConsoleLogger::CConsoleLogger(const char* source) : m_source(nullptr) {
		PutSource(source);
	}

	CConsoleLogger::~CConsoleLogger() {
		if (m_source) delete m_source;
	}

	const char* CConsoleLogger::GetSource() { return m_source; }

	void CConsoleLogger::PutSource(const char* source) {
#ifdef _DEBUG
		if (source == nullptr) throw std::exception("Source cannot be null");
#endif
	//	if (m_source != nullptr) delete m_source;
		if (m_source) delete m_source;	// not null is true in C/C++ logic
		auto length = strlen(source) + 1;
		m_source = new char[length + 1];
		strcpy_s(m_source, length, source);
	}

	CConsoleLogger::CConsoleLogger(CConsoleLogger& obj) : m_source(nullptr) {
		PutSource(obj.m_source);
	}

	void CConsoleLogger::Write(const char* message, LogType logType) {
		switch (logType) {
			case LogType::Information: printf("[%s] Information(\"%s\")\n", m_source, message); break;
			case LogType::Warning: printf("[%s] Warning(\"%s\")\n", m_source, message); break;
			case LogType::Error: printf("[%s] Error(\"%s\")\n", m_source, message); break;
		}
	}

}
