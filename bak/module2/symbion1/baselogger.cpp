//	baselogger.cppp

#include "pch.h"

namespace symbion {

	CBaseLogger::CBaseLogger() : m_source(nullptr) {
		Source = "CBaseLogger"; // PutSource("CBaseLogger");
	}

	CBaseLogger::CBaseLogger(const char* source) : m_source(nullptr) {
		Source = source; // PutSource(source);
	}

	CBaseLogger::~CBaseLogger() {
		if (m_source) delete m_source;
	}

	const char* CBaseLogger::GetSource() const { return m_source; }

	void CBaseLogger::PutSource(const char* source) {
#ifdef _DEBUG
		if (source == nullptr) throw std::exception("Source cannot be null");
#endif
		//	if (m_source != nullptr) delete m_source;
		if (m_source) delete m_source;	// not null is true in C/C++ logic
		auto length = strlen(source) + 1;
		m_source = new char[length + 1];
		strcpy_s(m_source, length, source);
	}

	CBaseLogger::CBaseLogger(const CBaseLogger& obj) : m_source(nullptr) {
		//	Source = obj.m_source; // PutSource(obj.m_source);	// PutSource(obj.GetSource());
		Source = obj.Source;	// PutSource(obj.GetSource());
	}

	void CBaseLogger::Message(const char* message) const {
		Write(message, LogType::Information);
	}

	void CBaseLogger::Warning(const char* message) const {
		Write(message, LogType::Warning);
	}

	void CBaseLogger::Failure(const char* message) const {
		Write(message, LogType::Error);
	}

	//const char* CBaseLogger::GetLogTypeText(LogType logType) {
	//	switch (logType) {
	//		case LogType::Information	: return "Information"; 
	//		case LogType::Warning		: return "Warning";
	//		case LogType::Error			: return "Error";
	//		default						: return "Message";
	//	//	default						: throw new std::exception("Invalid log type");
	//	}
	//}

	const char *CBaseLogger::GetLogTypeText(LogType logType) {
		static const char* strings[] = {
			"Information", "Warning", "Error", "Message"
		};
		int type = (int)logType;
		if (type < 0 || type > 2) type = 3;
	//	if (type < 0 || type > 2) throw new std::exception("Invalid log type");
		return strings[type];
	}

}
