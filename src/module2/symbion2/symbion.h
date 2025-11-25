#pragma once

#ifdef _WINDLL
#define SYMBION_API __declspec(dllexport)
#else
#define SYMBION_API __declspec(dllimport)
#endif

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
	class SYMBION_API CBaseLogger {
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
		virtual ~CBaseLogger();
		static const char* GetLogTypeText(LogType logType);
	};

	// Derived class
	class SYMBION_API CConsoleLogger : public CBaseLogger {
	public:
		CConsoleLogger();
		CConsoleLogger(const char* source);
		void Write(const char* message, LogType logType) const override;
	};

	class SYMBION_API CDebugLogger : public CBaseLogger {
	public:
		CDebugLogger();
		CDebugLogger(const char* source);
		void Write(const char* message, LogType logType) const override;
	};

	class SYMBION_API CFileLogger : public CBaseLogger {
	private:
		char* m_filename;

	public:
		CFileLogger();
		CFileLogger(const char* source);
		CFileLogger(const CFileLogger& obj);
		void PutSource(const char* source);
		void Write(const char* message, LogType logType) const override;
		~CFileLogger();
	private:
		void UpdateFilename();
	};

	class SYMBION_API CLoggerPtr {
	private:
		CBaseLogger* m_ptr;

	public:
		CLoggerPtr();
		CLoggerPtr(CBaseLogger* ptr);
		CLoggerPtr(const CLoggerPtr& obj);
		~CLoggerPtr();
		void PutPtr(CBaseLogger* ptr);
		CBaseLogger* GetPtr() const;
		operator CBaseLogger* () const;
		CLoggerPtr& operator = (CBaseLogger* ptr);
		CBaseLogger * operator ->() const;
	};

	class SYMBION_API CLoggerFactory {
	private:
		// static std::unique_ptr<CBaseLogger> m_pInstance;
		static CLoggerPtr m_pInstance;
	public:
		static CBaseLogger* CreateInstance();
		static CBaseLogger* GetInstance();
	};
}