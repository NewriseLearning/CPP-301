//	symbion.h

#pragma once

//#define LOGTYPE_INFORMATION 0
//#define LOGTYPE_WARNING 1
//#define LOGTYPE_ERROR 2

#include <cstdint>	// C++ header file for stdint.h

#define SAFE_DELETE(ptr) delete ptr; ptr = nullptr;

#ifndef abstract 
#define abstract = 0	// pure virtual function
#endif

namespace symbion {
	enum struct LogType : uint8_t {
		Information,
		Warning,
		Error
	};

	class CBaseLogger {
	private:
		char* m_source;
	public:
		CBaseLogger();
		CBaseLogger(const CBaseLogger& obj);
		CBaseLogger(const char* source);
		virtual ~CBaseLogger();
		virtual const char* GetSource() const;
		virtual void PutSource(const char* source);
		virtual void Write(const char* message, LogType logType) const = 0;
//		virtual void Write(const char* message, LogType logType) const abstract;
		void Message(const char* message) const;
		void Warning(const char* message) const;
		void Failure(const char* message) const;
		static const char *GetLogTypeText(LogType logType);
	public:
		__declspec(property(get = GetSource, put = PutSource)) const char* Source;
	};

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

	class CFileLogger : public CBaseLogger {
	private:
		char* m_filename;
	public:
		CFileLogger();
		CFileLogger(const char* source);
		CFileLogger(const CFileLogger& obj);
		const char* GetFilename() const;
		void PutSource(const char* source) override;
		void Write(const char* message, LogType logType) const override;
		~CFileLogger();
	private:
		void UpdateFilename();
	};

	class CLoggerPtr {
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
		CLoggerPtr& operator =(CBaseLogger* ptr);
		CBaseLogger* operator ->() const;
	};

	class CLoggerFactory {
	private:
		static CBaseLogger* m_pInstance;
	public:
		static CBaseLogger* CreateInstance();
		static CBaseLogger* GetInstance();
	};


}
