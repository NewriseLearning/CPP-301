#include "MyLog.h"

using namespace mylog;

CServiceRepository repository;

void log() {
	auto logger = repository.Lookup<ILogger>();
	if (logger != nullptr) {
		logger->Message(_t("Hello!"));
		logger->Message(_t("Goodbye!"));
	}
}

int main() {
	CDefaultLogger logger;
	repository.Inject<ILogger>(&logger);
	log();
	return 0;
}