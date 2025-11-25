#include "Unicode2.h"


int main() {
	_tstring t1(_t("Hello!"));
	_tstring t2(_t("Goodbye!"));
	_tcout << t1 << endl << t2 << endl;
	return 0;
}
