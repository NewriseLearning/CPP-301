#pragma once

#ifdef UNICODE
#define _tstring wstring
#define _tcin wcin
#define _tcout wcout
#define _t(str)	L##str
#else
#define _tstring string
#define _tcin cin
#define _tcout cout
#define _t(str) str
#endif

#include <windows.h>
#include <tchar.h>
#include <cstdint>
#include <string>

namespace mylog {

	enum struct LogType : uint16_t {
		Information,
		Warning,
		Error
	};

	struct __declspec(novtable) ILogger {
		virtual void PutSource(const std::_tstring& source) = 0;
		virtual const std::_tstring& GetSource() const = 0;
		virtual void Write(const std::_tstring& message,
			LogType type = LogType::Information) const = 0;
		virtual void Message(const std::_tstring& message) const = 0;
		virtual void Warning(const std::_tstring& message) const = 0;
		virtual void Failure(const std::_tstring& message) const = 0;
		virtual void Release() const = 0;
		__declspec(property(get = GetSource, put = PutSource))
			const std::_tstring& Source;
	};

	typedef ILogger* (*GetLoggerPtr)();

	class CDefaultLogger : public ILogger {
	private:
		std::_tstring m_source;
	public:
		CDefaultLogger();
		void PutSource(const std::_tstring& source);
		const std::_tstring& GetSource() const;
		void Write(const std::_tstring& message,
			LogType type = LogType::Information) const;
		void Message(const std::_tstring& message) const;
		void Warning(const std::_tstring& message) const;
		void Failure(const std::_tstring& message) const;
		void Release() const;
		virtual ~CDefaultLogger();
	};

	const std::_tstring& GetLogTypeString(LogType type);
	
	class CLoggerFactory {
	private:
		HMODULE m_hModule;
		GetLoggerPtr m_pGetLogger;
	public:
		CLoggerFactory();
		CLoggerFactory(const CLoggerFactory& obj);
		ILogger* GetInstance() const;
		~CLoggerFactory();
	};

}	// namespace mylog
