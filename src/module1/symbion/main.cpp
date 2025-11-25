#include "symbion.h"
#include <cstdio>



using namespace symbion;

int main1() {
//	CConsoleLogger log;
//	log.PutSource("symbion");
	CConsoleLogger log("symbion");
	log.Write("This is the 1st message.", LogType::Information);
	log.Write("This is the 2nd message.", LogType::Warning);
	log.Write("This is the 3rd message.", LogType::Error);
//	puts(log.GetSource());
	return 0;
}

int main2() {
	CConsoleLogger log_0;	// CConsoleLogger()
	CConsoleLogger log_1("symbion");	// CConsoleLogger(const char * source)
	CConsoleLogger log_2(log_1);		// CConsoleLogger(CConsoleLogger& obj)

//	Assignment constructors
	CConsoleLogger log_3 = "symbion";	// CConsoleLogger(const char * source)
	CConsoleLogger log_4 = log_3;		// CConsoleLogger(CConsoleLogger& obj)

//	Initializer lists
	CConsoleLogger log_5 { "symbion" }; // CConsoleLogger(const char * source)
	CConsoleLogger log_6 { log_5 }; // CConsoleLogger(CConsoleLogger& obj)

	log_0.Write("Hello 0", LogType::Information);
	log_1.Write("Hello 1", LogType::Information);
	log_2.Write("Hello 2", LogType::Information);
	log_3.Write("Hello 3", LogType::Information);
	log_4.Write("Hello 4", LogType::Information);
	log_5.Write("Hello 5", LogType::Information);
	log_6.Write("Hello 6", LogType::Information);

	return 0;
}

int main3() {
	const CConsoleLogger log;
//	log.PutSource("symbion");
	puts(log.GetSource());
	log.Write("Hello log!", LogType::Information);
	return 0;
}

CConsoleLogger log_0;	// global static object

const CConsoleLogger get_log() {
	CConsoleLogger log;	// local object
	log.PutSource("symbion");
	return log;
}

CConsoleLogger* pLog = nullptr;

int main4() {
	log_0.Write("Hello!", LogType::Information);
	auto log_copy = get_log();
	log_copy.Write("Hello copy!", LogType::Information);

	// inline object
	CConsoleLogger("symbion").Write("Hello inline!", LogType::Information);

	pLog = new CConsoleLogger("symbion");
	pLog->Write("Hello dynamic!", LogType::Information);
//	delete pLog; pLog = nullptr;
	SAFE_DELETE(pLog)

	return 0;

}

int main5() {
	CConsoleLogger log("symbion");
	log.Message("Information!");
	log.Warning("Warning!");
	log.Failure("Error!");

	log.Source = "sym2";	// log.PutSource("sym2");
	puts(log.Source);		// puts(log.GetSource());

	return 0;
}

int main6() {
	CConsoleLogger obj;
	obj.Message("Hello CConsoleLogger!");
	puts(CBaseLogger::GetLogTypeText(LogType::Information));
	puts(CBaseLogger::GetLogTypeText(LogType::Warning));
	puts(CBaseLogger::GetLogTypeText(LogType::Error));
	return 0;
}

void UseLogger(CBaseLogger* pLog) {
	pLog->Message("Hello!");
	pLog->Message("Goodbye!");
	SAFE_DELETE(pLog);
}

int main7() {
	UseLogger(new CConsoleLogger());
	UseLogger(new CDebugLogger());
	UseLogger(new CFileLogger());
	return 0;
}

int main() {
	CLoggerFactory factory;
	CBaseLogger *pLog = factory.CreateInstance();
	pLog->Message("Hello!");
	pLog->Message("Goodbye!");
	SAFE_DELETE(pLog);
	return 0;
}

