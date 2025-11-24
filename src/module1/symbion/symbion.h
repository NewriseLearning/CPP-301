#pragma once

#include <cstdint>

namespace symbion {
	enum struct LogType : uint8_t {
		Information, Warning, Error
	};

	class CConsoleLogger {
	private:
		char* m_source;
	public:
		CConsoleLogger();
		CConsoleLogger(const char* source);
		const char* GetSource();
		void PutSource(const char* source);
		void Write(const char* message, LogType logType);
		~CConsoleLogger();
	};
}