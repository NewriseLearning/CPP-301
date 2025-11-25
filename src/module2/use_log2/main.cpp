#include <symbion2.h>

int main() {
	auto pLog = symbion::CLoggerFactory::GetInstance();
	pLog->Source = "use_log2";
	pLog->Message("Hello!");
	pLog->Message("Goodbye!");
	return 0;
}
