#include "..\symbion2\symbion.h"

int main() {
	auto pLog = symbion::CLoggerFactory::GetInstance();
	pLog->PutSource("test_log2");
	pLog->Message("Hello!");
	pLog->Message("Goodbye!");
	SAFE_DELETE(pLog)
		return 0;
}
