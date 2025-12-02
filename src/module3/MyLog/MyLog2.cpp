//	MyLog2.cpp

#include "MyLog.h"
#include <windows.h>
#include <tchar.h>

namespace mylog {
//	CDefaultLogger::CDefaultLogger() : m_source(_t("Log")) {
	CDefaultLogger::CDefaultLogger() {
		PutSource(_t("Log"));	// Source = _t("Log");
	}
	
	void CDefaultLogger::PutSource(const std::_tstring& source) {
		m_source = source;
	}

	const std::_tstring& CDefaultLogger::GetSource() const {
		return m_source;
	}

	void CDefaultLogger::Write(const std::_tstring& message, LogType type) const {
		TCHAR text[1024];
		const std::_tstring& type_str = GetLogTypeString(type);
		_stprintf_s(text, _TEXT("[%s] %s(\"%s\")\n"),
			m_source.c_str(), type_str.c_str(), message.c_str());
		OutputDebugString(text);
	}

	void CDefaultLogger::Message(const std::_tstring& message) const {
		Write(message, LogType::Information);
	}

	void CDefaultLogger::Warning(const std::_tstring& message) const {
		Write(message, LogType::Warning);
	
	}
	void CDefaultLogger::Failure(const std::_tstring& message) const {
		Write(message, LogType::Error);
	}

	void CDefaultLogger::Release() const {
		delete this;	// destroy the current object
	}

	CDefaultLogger::~CDefaultLogger() {
		//	blank implementation to be inherited by derived classes
		//	if they choose not to override
	}

}	// namespace mylog
