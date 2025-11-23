//	main.cpp

#include "symbion.h"
#include <memory>


// using symbion::LogType;
// using symbion::CConsoleLogger;

using namespace symbion;

#include <cstdio>
#include <cstring>
#include <exception>

int main1() {
	//	CConsoleLogger log;
	//	log.PutSource("symbion");
	try {
		CConsoleLogger log("symbion");
		CConsoleLogger log2 = log;
	//	log.PutSource(nullptr);
		log.Write("This is the 1st message.", LogType::Information);
		log.Write("This is the 2nd message.", LogType::Warning);
		log.Write("This is the 3rd message.", LogType::Error);
		log2.Write("This is the 1st message.", LogType::Information);
		log2.Write("This is the 2nd message.", LogType::Warning);
		log2.Write("This is the 3rd message.", LogType::Error);
	}
	catch (std::exception e) {
		puts(e.what());
	}
	return 0;
}

int main2() {
	CConsoleLogger* p1 = new CConsoleLogger("symbion");
	CConsoleLogger* p2 = new CConsoleLogger(*p1);
	p1->Write("Hello1!", LogType::Information);
	p2->Write("Hello2!", LogType::Information);
	p1->Write("Goodbye1!", LogType::Information);
	delete p1;
	p2->Write("Goodbye2!", LogType::Information);
	delete p2;
	return 0;
}

int main3() {
	CConsoleLogger log_0;	// CConsoleLogger()
	CConsoleLogger log_1("symbion");	// CConsoleLogger(const char *source);
	CConsoleLogger log_2(log_1);		// CConsoleLogger(CConsoleLogger& obj);
	log_0.Write("Hello 0!", LogType::Information);
	log_1.Write("Hello 1!", LogType::Information);
	log_2.Write("Hello 2!", LogType::Information);

	CConsoleLogger log_3 = "symbion"; // CConsoleLogger(const char *source);
	CConsoleLogger log_4 = log_3;	// CConsoleLogger(CConsoleLogger& obj);
	log_3.Write("Hello 3!", LogType::Information);
	log_4.Write("Hello 4!", LogType::Information);

//	CConsoleLogger log_5 = { "symbion" }; // CConsoleLogger(const char *source);
	CConsoleLogger log_5 { "symbion" }; // CConsoleLogger(const char *source);
	log_5.Write("Hello 5!", LogType::Information);
	return 0;
}

void func1(int n) {
	if (n == 0) n = 123;
	printf("n = %d\n", n);
}

void func2(int* n) {
	if (*n == 0) *n = 123;
	printf("n = %d\n", *n);
}

void func3(int& n) {
	if (n == 0) n = 123;
	printf("n = %d\n", n);
}

int main4() {
	int a = 0;
	func1(a);	// passed by value (passing a copy)
	printf("a = %d\n", a);

	func2(&a);	// passed by pointer (passing location of original)
	printf("a = %d\n", a);

	a = 0;
	func3(a);	// passed by reference (passing only original)
	printf("a = %d\n", a);

	return 0;
}

void logTo(const CConsoleLogger log) {
	log.Write("Using a constant logger.", LogType::Information);
}

int main5() {
	CConsoleLogger log;
	log.PutSource("symbion");
	logTo(log);
	return 0;
}

CConsoleLogger log_0;	// (static memory, global access) created before main, destroyed after main (program terminates)

const CConsoleLogger get_log() {
	CConsoleLogger log; // (stack memory, local access) created before get_log, destroy after get_log
	log.PutSource("symbion");
	// safe to return a copy of a local object
	// never return the original object (by pointer or reference)
	// because local object is destroyed at end of function
	return log;
}

int main6() {
	static CConsoleLogger log_1; // (static memory, local access)
	log_0.Write("Hello 0!", LogType::Information);
	log_1.Write("Hello 1!", LogType::Information);

	const CConsoleLogger& log = get_log();	// getting a reference to the copy returned
	log.Write("Hello 2!", LogType::Information); // using the copy

	// inline object created for one statement, destroyed at end of statement)
	CConsoleLogger("symbion").Write("Hello inline!", LogType::Information);

//	CConsoleLogger* pLog = nullptr;
//	if (!pLog) pLog = new CConsoleLogger("symbion");
//	if (pLog) pLog->Write("Hello dynamic!", LogType::Information);

	CConsoleLogger* pLog = new CConsoleLogger("symbion");
	pLog->Write("Hello dynamic!", LogType::Information);

//	delete pLog;
//	pLog = nullptr;
	SAFE_DELETE(pLog)

	return 0;
}

int main7() {
	CConsoleLogger log;
	log.Source = "symbion";	// log.PutSource("symbion");
	puts(log.Source);	// puts(log.GetSource());
	log.Message("This is information message!");
	log.Warning("This is warning message!");
	log.Failure("This is error message!");
	return 0;
}

void useLog(const CBaseLogger& log) {
	log.Message("Hello!");
	log.Message("Goodbye!");
}

void useLog(const CBaseLogger *log) {
	log->Message("Hello!");
	log->Message("Goodbye!");
}

int main8() {
	puts(CBaseLogger::GetLogTypeText(LogType::Information));
	puts(CBaseLogger::GetLogTypeText(LogType::Warning));
	puts(CBaseLogger::GetLogTypeText(LogType::Error));
	CConsoleLogger log1;
	useLog(log1);
	useLog(&log1);
	CDebugLogger log2;
	useLog(log2);
	useLog(&log2);
	CFileLogger log3("symbion");
	useLog(log3);
	useLog(&log3);
	return 0;
}

// Why destructors should be virtual in polymorphic types?
// virtual functions are called based on object
// non-virtual functions are called based on type
// virtual destructor ensures we are always calling the correct destructor

class Abc { 
public:
	virtual void foo() { }
};

int main9() {
//	printf("size:%d\n", sizeof(CBaseLogger));
	printf("size:%d\n", sizeof(Abc));	// 4 bytes (pointer to v-tbl)
	CBaseLogger* pLog = new CFileLogger("symbion");
	pLog->Message("Hello!");	// Message will call CFileLogger::Write
	pLog->Message("Goodbye!");	// Message will call CFileLogger::Write
	delete pLog;	// ~CFileLogger() will call ~CBaseLogger()
	return 0;
}

int main10() {
//	useLog(CConsoleLogger());
//	useLog(CDebugLogger());
	CBaseLogger* pLog = CLoggerFactory::GetInstance();
	pLog->Source = "symbion";
	pLog->Message("Hello!");
	pLog->Message("Goodbye!");
	CLoggerFactory::GetInstance()->Message("Sayonara!");
	delete pLog;
	return 0;
}

// CLoggerPtr log(CLoggerFactory::GetInstance());
std::shared_ptr<CBaseLogger> log(CLoggerFactory::GetInstance());

int main() {
	std::shared_ptr<CBaseLogger> log2(log);
	log->Message("Hello!");
	log->Message("Goodbye!");
	log2->Message("Sayonara!");
}
