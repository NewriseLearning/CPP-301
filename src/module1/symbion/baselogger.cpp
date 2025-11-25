#include "cstdio"
#include "cstring"
#include "exception"
#include "symbion.h"

namespace symbion {
	CBaseLogger::CBaseLogger() : m_source(nullptr) {
		PutSource("CBaseLogger");	// CBaseLogger::PutSource("CBaseLogger");
	}

	CBaseLogger::CBaseLogger(const char* source) : m_source(nullptr) {
		PutSource(source);
	}

	CBaseLogger::CBaseLogger(const CBaseLogger& obj) : m_source(nullptr) {
		PutSource(obj.m_source);
	}

	//const char* CBaseLogger::GetLogTypeText(LogType logType) {
	//	switch (logType) {
	//		case LogType::Information: return "Information"; break;
	//		case LogType::Warning: return "Warning"; break;
	//		case LogType::Error: return "Error"; break;
	//	}
	//}

	const char* CBaseLogger::GetLogTypeText(LogType logType) {
		static const char* strings[] = { "Information", "Warning", "Error" };
		int type = (int)logType;
	//	if (type < 0 || type > 3) type = 3;
		return strings[type];
	}

	//void CBaseLogger::Message(const char* message) const {
	//	Write(message, LogType::Information);
	//}

	//void CBaseLogger::Warning(const char* message) const {
	//	Write(message, LogType::Warning);
	//}

	//void CBaseLogger::Failure(const char* message) const {
	//	Write(message, LogType::Error);
	//}

	/*const char* CBaseLogger::GetSource() const {
		return m_source;
	}*/

	void CBaseLogger::PutSource(const char* source) {
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

	CBaseLogger::~CBaseLogger() {
//		if (m_source != nullptr) delete m_source;
		if (m_source) delete m_source;
	}

}
