#include "..\symbion1\symbion.h"

int main() {
	auto pLog = symbion::CLoggerFactory::GetInstance();
	pLog->PutSource("test_log1");
	pLog->Message("Hello!");
	pLog->Message("Goodbye!");
	return 0;
}