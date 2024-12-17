//	symbion.h

#pragma once

//#define LOGTYPE_INFORMATION 0
//#define LOGTYPE_WARNING 1
//#define LOGTYPE_ERROR 2

#include <cstdint>	// C++ header file for stdint.h

namespace symbion {
	enum struct LogType : uint8_t {
		Information,
		Warning,
		Error
	};

	class CConsoleLogger {
	private:
		char *m_source;
	public:
		CConsoleLogger();
		CConsoleLogger(CConsoleLogger& obj);
	//	explicit CConsoleLogger(const char* source);
		CConsoleLogger(const char* source);
		~CConsoleLogger();	// destructor
		const char* GetSource();
		void PutSource(const char* source);
		void Write(const char* message, LogType logType);
	};
}
