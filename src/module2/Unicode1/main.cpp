//#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <tchar.h>

void GetComputerName1() {
	char computerName[256];
	DWORD dwLen = sizeof(computerName);
	GetComputerNameA(computerName, &dwLen);
	MessageBoxA(NULL, computerName, "Computer Name", MB_OK);
}

void GetComputerName2() {
	wchar_t computerName[256];
	DWORD dwLen = sizeof(computerName) / 2;
	GetComputerNameW(computerName, &dwLen);
	MessageBoxW(NULL, computerName, L"Computer Name", MB_OK);
}

void GetComputerName3() {
	TCHAR computerName[256];
	DWORD dwLen = sizeof(computerName) / sizeof(TCHAR);
	GetComputerName(computerName, &dwLen);
	MessageBox(NULL, computerName, _T("Computer Name"), MB_OK);
}

int main() {
	GetComputerName1();
	GetComputerName2();
	GetComputerName3();

//	char b1[128];		// 128 ANSI char array (128 bytes)
//	wchar_t b2[128];	// 128 Unicode char array (256 bytes)
	CHAR b1[128];		// 128 ANSI char array (128 bytes) (same as char)
	WCHAR b2[128];		// 128 Unicode char array (256 bytes) (same as wchar_t)
	TCHAR b3[128];		// 128 ANSI/Unicode char array (128/256 bytes)

//	const char* p1 = "This is an ANSI string!";
//	const wchar_t* p2 = L"This is an Unicode string!";
	LPCSTR p1 = "This is an ANSI string!";
	LPCWSTR p2 = L"This is an Unicode string!";
	LPCTSTR p3 = _T("This is an ANSI/Unicode string!");

	LPSTR s1 = b1;
	LPWSTR s2 = b2;
	LPTSTR s3 = b3;

//	strcpy(s1, p1);	// copy ANSI string
//	wcscpy(s2, p2); // copy Unicode string
//	_tcscpy(s3, p3); // copy either ANSI/Unicode string

//	strcpy_s(b1, p1);
//	wcscpy_s(b2, p2);
//	_tcscpy_s(b3, p3);
	strcpy_s(s1, sizeof(b1), p1);
	wcscpy_s(s2, sizeof(b2) / 2, p2);
	_tcscpy_s(s3, sizeof(b3) / sizeof(TCHAR), p3);


	return 0;
}