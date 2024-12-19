#include "MyLog.h"
#include <array>

namespace mylog {
	const std::_tstring& GetLogTypeString(LogType type) {
		static std::array<std::_tstring, 4> strings = {
			std::_tstring(_t("Information")),
			std::_tstring(_t("Warning")),
			std::_tstring(_t("Error")),
		};

		auto index = (uint16_t)type;
		if (index < 0 || index > 2) index = 3;
		return strings[index];
	}

	CDefaultLogger::CDefaultLogger() {
		PutSource(_t("Log"));
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
		_stprintf_s(text, _t("[%s] %s(\"%s\")\n"),
			m_source.c_str(), type_str.c_str(),
			message.c_str());
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
		delete this;
	}
	CDefaultLogger::~CDefaultLogger() {
		// blank implementation to be inherited by derived classes
	}
}