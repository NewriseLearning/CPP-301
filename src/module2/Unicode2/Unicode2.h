#pragma once

#include <string>
#include <iostream>
using namespace std;

#ifdef _UNICODE
#define _tstring wstring
#define _tcin wcin
#define _tcout wcout
#define _t(str) L##str
#else
#define _tstring string
#define _tcin cin
#define _tcout cout
#define _t(str)	str
#endif


