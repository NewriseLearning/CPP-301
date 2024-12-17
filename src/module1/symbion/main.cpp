//	main.cpp

#include "symbion.h"

// using symbion::LogType;
// using symbion::CConsoleLogger;

using namespace symbion;

#include <cstdio>

int main() {

	CConsoleLogger log;
	log.PutSource("symbion");
	log.Write("This is the 1st message.", LogType::Information);
	log.Write("This is the 2nd message.", LogType::Warning);
	log.Write("This is the 3rd message.", LogType::Error);
	return 0;
}
