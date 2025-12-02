#include "..\MyLog\MyLog.h"

using namespace mylog;

// mylog::CServiceRepository repository;
CServiceRepository repository;

void log() {
	ILogger *logger = repository.Lookup<ILogger>();
	if (logger != nullptr) logger->Message(_T("Hello!"));
	//else {
	//	CLoggerFactory factory;
	//	logger = factory.GetInstance();
	//	repository.Inject<ILogger>(logger);
	//	logger->Message(_T("Hello!"));
	//}
}

int main() {
	CDefaultLogger logger;
	repository.Inject<ILogger>(&logger);
	log();
	return 0;
}