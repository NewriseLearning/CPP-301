#include "..\MyLog\MyLog.h"

class CEventLogger : public mylog::CDefaultLogger {
public:
	void Write(const std::_tstring& message, mylog::LogType type) const override {
		WORD eventType = 0;
		switch (type) {
			case mylog::LogType::Information:
				eventType = EVENTLOG_INFORMATION_TYPE;
				break;
			case mylog::LogType::Warning:
				eventType = EVENTLOG_WARNING_TYPE;
				break;
			case mylog::LogType::Error:
				eventType = EVENTLOG_ERROR_TYPE;
				break;
		}
		LPCTSTR messages[] = { message.c_str() };
		HANDLE hEventLog = RegisterEventSource(NULL, Source.c_str());
		ReportEvent(hEventLog, eventType, 0, 0, NULL, 1, 0, messages, NULL);
		DeregisterEventSource(hEventLog);
	}
};

extern "C" mylog::ILogger * GetLogger() {
	return new CEventLogger();
}
