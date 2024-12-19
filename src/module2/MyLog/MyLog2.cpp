#include "mylog.h"

namespace mylog {
	CLoggerFactory::CLoggerFactory() : m_hModule(nullptr), m_pGetLogger(nullptr) {
		TCHAR moduleName[MAX_PATH];
		if (GetEnvironmentVariable(_t("ILogger"), moduleName, MAX_PATH) == 0) return;
		if ((m_hModule = LoadLibrary(moduleName)) == nullptr) return;
		m_pGetLogger = (GetLoggerPtr)GetProcAddress(m_hModule, "GetLogger");
	}

	CLoggerFactory::CLoggerFactory(const CLoggerFactory& obj) : 
		m_hModule(nullptr), m_pGetLogger(nullptr) {
		if (obj.m_hModule == nullptr) return;
		auto process = GetCurrentProcess();
		DuplicateHandle(
			process, obj.m_hModule,
			process, (LPHANDLE)&m_hModule,
			NULL, FALSE, DUPLICATE_SAME_ACCESS);
		m_pGetLogger = (GetLoggerPtr)GetProcAddress(m_hModule, "GetLogger");
	}

	ILogger* CLoggerFactory::GetInstance() const {
		//if (m_pGetLogger != nullptr) return m_pGetLogger();
		//return new CDefaultLogger();
		return m_pGetLogger != nullptr ? m_pGetLogger() : new CDefaultLogger();
	}

	CLoggerFactory::~CLoggerFactory() {
		if (m_hModule != nullptr) FreeLibrary(m_hModule);
	}
}
