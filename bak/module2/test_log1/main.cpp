#include <symbion.h>

int  main() {
	auto pLog = symbion::CLoggerFactory::GetInstance();
	pLog->PutSource("test_log1");
	pLog->Message("Hello!");
	pLog->Message("Goodbye!");
	SAFE_DELETE(pLog)
	return 0;
}