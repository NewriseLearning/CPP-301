#include "symbion.h"
#include <cstdio>

using namespace symbion;

int main() {
//	CConsoleLogger log;
//	log.PutSource("symbion");
	CConsoleLogger log("symbion");
	log.Write("This is the 1st message.", LogType::Information);
	log.Write("This is the 2nd message.", LogType::Warning);
	log.Write("This is the 3rd message.", LogType::Error);
//	puts(log.GetSource());
	return 0;
}