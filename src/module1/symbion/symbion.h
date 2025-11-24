#pragma once

#include <cstdint>

#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr)	\
	delete ptr;				\
	ptr = nullptr;
#endif

namespace symbion {
	enum struct LogType : uint8_t {
		Information, Warning, Error
	};


	// Base class
	class CBaseLogger {
	protected:
		char* m_source;
	public:
		CBaseLogger();
		CBaseLogger(const char* source);
		CBaseLogger(const CBaseLogger& obj);
		const char* GetSource() const { return m_source; }
		virtual void PutSource(const char* source);
		__declspec(property(get = GetSource, put = PutSource)) const char* Source;
	//	virtual void Write(const char* message, LogType logType) const = 0;
		virtual void Write(const char* message, LogType logType) const abstract;
		void Message(const char* message) const { Write(message, LogType::Information); }
		void Warning(const char* message) const { Write(message, LogType::Warning); }
		void Failure(const char* message) const { Write(message, LogType::Error); }
		~CBaseLogger();
		static const char* GetLogTypeText(LogType logType);
	};

	// Derived class
	class CConsoleLogger : public CBaseLogger {
	public:
		CConsoleLogger();
		CConsoleLogger(const char* source);
		void Write(const char* message, LogType logType) const override;
	};

	class CDebugLogger : public CBaseLogger {
	public:
		CDebugLogger();
		CDebugLogger(const char* source);
		void Write(const char* message, LogType logType) const override;
	};
}