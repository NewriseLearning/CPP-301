#include "..\MyLog\MyLog.h"

using namespace mylog;

int main() {
	CLoggerFactory factory;
	ILogger *pLog = factory.GetInstance();
	pLog->Write(_t("Hello!"));
	pLog->Write(_t("Goodbye!"));
	pLog->Release();
	return 0;
}
