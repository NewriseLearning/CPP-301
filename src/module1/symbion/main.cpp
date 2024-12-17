//	main.cpp

#include "symbion.h"

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

int main() {
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
}
