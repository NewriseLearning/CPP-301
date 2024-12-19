#include "..\MyLog\MyLog.h"

#include <ctime>
#include <fstream>

#ifdef UNICODE
#define _tfstream wfstream
#else
#define _tfstream fstream
#endif

class CFileLogger : public mylog::CDefaultLogger {
public:
	void Write(const std::_tstring& message, mylog::LogType type) const override {
		tm datetime;
		auto now = time(nullptr);
		localtime_s(&datetime, &now);
		TCHAR text[2048];
		_stprintf_s(text,
			_t("[%04d-%02d-%02d %02d:%02d:%02d] %s(\"%s\")"),
			datetime.tm_year + 1900, datetime.tm_mon, datetime.tm_mday,
			datetime.tm_hour, datetime.tm_min, datetime.tm_sec,
			GetLogTypeString(type).c_str(), message.c_str());
		std::_tstring contents(text);
		std::_tstring filename(Source);
		filename.append(_t(".log"));
		std::_tfstream file(filename, std::ios::app);
		file << contents << std::endl;
		file.close();
	}
};

extern "C" mylog::ILogger* GetLogger() {
	return new CFileLogger();
}
