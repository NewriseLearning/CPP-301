#include "symbion.h"
#include <fstream>
#include <ctime>	// C++ version of time.h
#include <cstring>

namespace symbion {
	CFileLogger::CFileLogger() : m_filename(nullptr), CBaseLogger("CFileLogger") {
		UpdateFilename();
	}
	CFileLogger::CFileLogger(const char* source) : m_filename(nullptr), CBaseLogger(source) {
		UpdateFilename();
	}
	CFileLogger::CFileLogger(const CFileLogger& obj) : m_filename(nullptr), CBaseLogger(obj) {
		UpdateFilename();
	}

	const char* CFileLogger::GetFilename() const { return m_filename; }

	void CFileLogger::PutSource(const char* source) {
		CBaseLogger::PutSource(source);
		UpdateFilename();
	}

	void CFileLogger::Write(const char* message, LogType logType) const {
		tm datetime;
		char text[2048];
		auto now = time(nullptr);
		localtime_s(&datetime, &now);
		sprintf_s(text,
			"[%04d-%02d-%02d %02d:%02d:%02d] %s(\"%s\")",
			datetime.tm_year + 1900, datetime.tm_mon, datetime.tm_mday,
			datetime.tm_hour, datetime.tm_min, datetime.tm_sec,
			GetLogTypeText(logType), message);
		std::fstream file(m_filename, std::ios::app);
		file << text << std::endl;
		file.close();
	}

//	CFileLogger::~CFileLogger() : ~CBaseLogger() {
	CFileLogger::~CFileLogger() {
		if (m_filename) delete m_filename;
	}
	void CFileLogger::UpdateFilename() {
		if (m_filename) delete m_filename;
		auto length = strlen(Source) + 5;
		m_filename = new char[length];
		strcpy_s(m_filename, length, Source);
		strcat_s(m_filename, length, ".log");
	}
}
