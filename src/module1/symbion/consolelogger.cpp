#include "cstdio"
#include "cstring"
#include "exception"
#include "symbion.h"

namespace symbion {
	CConsoleLogger::CConsoleLogger() : m_source(nullptr) {
		PutSource("CConsoleLogger");
	}

	CConsoleLogger::CConsoleLogger(const char* source) : m_source(nullptr) {
		PutSource(source);
	}


	void CConsoleLogger::Write(const char* message, LogType logType) {
		switch (logType) {
			case LogType::Information: printf("[%s] Information(\"%s\")\n", m_source, message); break;
			case LogType::Warning: printf("[%s] Warning(\"%s\")\n", m_source, message); break;
			case LogType::Error: printf("[%s] Error(\"%s\")\n", m_source, message); break;
		}
	}

	const char* CConsoleLogger::GetSource() {
		return m_source;
	}
	void CConsoleLogger::PutSource(const char* source) {
		// if (source == nullptr) throw std::exception("Source cannot be null");
#ifdef DEBUG
		if (!source) throw std::exception("Source cannot be null");
#endif
//		if (m_source != nullptr) delete m_source;
		if (m_source) delete m_source;
		auto length = strlen(source) + 1;
		m_source = new char[length];
		strcpy_s(m_source, length, source);
	}

	CConsoleLogger::~CConsoleLogger() {
//		if (m_source != nullptr) delete m_source;
		if (m_source) delete m_source;
	}

}
