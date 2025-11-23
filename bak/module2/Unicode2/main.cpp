#include <windows.h>
#include <iostream>

#ifdef UNICODE
#define _tstring wstring
#define _tcin wcin
#define _tcout wcout
#define _t(str)	L##str
#else
#define _tstring string
#define _tcin cin
#define _tcout cout
#define _t(str) str
#endif

int main() {
	std::_tstring t1(_t("Hello!"));
	std::_tstring t2(_t("Goodbye!"));
	std::_tcout << t1 << std::endl;
	std::_tcout << t2 << std::endl;

	TCHAR buffer[256];
	std::_tcout << _t("Enter your name:");
	std::_tcin.getline(buffer, sizeof(buffer) / sizeof(TCHAR));
	std::_tstring name(buffer);
	std::_tcout << _t("Hello ") << name << _t('!') << std::endl;
	return 0;
}
