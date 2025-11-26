// MyLog3.cpp

#include "MyLog.h"

namespace mylog {
	CLoggerFactory::CLoggerFactory() : m_hModule(nullptr), m_pGetLogger(nullptr) {
		TCHAR moduleName[MAX_PATH];
		if (GetEnvironmentVariable(TEXT("ILogger"), moduleName, MAX_PATH) == 0) return;
		if ((m_hModule = LoadLibrary(moduleName)) == nullptr) return;
		m_pGetLogger = (GetLoggerPtr)GetProcAddress(m_hModule, "GetLogger");
	}

	CLoggerFactory::CLoggerFactory(const CLoggerFactory& obj) : m_hModule(nullptr), m_pGetLogger(nullptr) {
		if (!obj.m_hModule) return;
		auto process = GetCurrentProcess();
		DuplicateHandle(
			process, obj.m_hModule,
			process, (LPHANDLE)&m_hModule,
			NULL, FALSE, DUPLICATE_SAME_ACCESS);
		m_pGetLogger = (GetLoggerPtr)GetProcAddress(m_hModule, "GetLogger");
	}

	ILogger* CLoggerFactory::GetInstance() const {
		return m_pGetLogger ? m_pGetLogger() : new CDefaultLogger();
	}

	CLoggerFactory::~CLoggerFactory() {
		if (m_hModule) FreeLibrary(m_hModule);
	}

}	// namespace mylog
