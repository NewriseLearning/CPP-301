#include <windows.h>
#include <tchar.h>

void GetComputerName1() {
	CHAR computerName[256];
	DWORD dwLen = sizeof(computerName);
	GetComputerNameA(computerName, &dwLen);
	MessageBoxA(NULL, computerName, "Computer Name", MB_OK);
}

void GetComputerName2() {
	WCHAR computerName[256];
	DWORD dwLen = sizeof(computerName) / 2;
	GetComputerNameW(computerName, &dwLen);
	MessageBoxW(NULL, computerName, L"Computer Name", MB_OK);
}

void GetComputerName3() {
	TCHAR computerName[256];
	DWORD dwLen = sizeof(computerName) / sizeof(TCHAR);
	GetComputerName(computerName, &dwLen);
	MessageBox(NULL, computerName, TEXT("Computer Name"), MB_OK);
}

int main() {
	CHAR b1[128]; // 128-bytes
	WCHAR b2[128]; // 256-bytes
	TCHAR b3[128]; // 128/256 bytes

	LPCSTR p1 = "This is an ANSI string."; // const char *
	LPCWSTR p2 = L"This is a Unicode string.";	// const wchar_t *
//	LPCTSTR p3 = TEXT("This is either ANSI/Unicode string."); // const TCHAR *
	LPCTSTR p3 = _T("This is either ANSI/Unicode string."); // const TCHAR *

	strcpy_s(b1, p1);
	wcscpy_s(b2, p2);
	_tcscpy_s(b3, p3);

	LPSTR s1 = b1;	// char *
	LPWSTR s2 = b2;	// wchar_t *
	LPTSTR s3 = b3; // TCHAR *

	strcpy_s(s1, sizeof(b1), p1);
	wcscpy_s(s2, sizeof(b2) / 2, p2);
	_tcscpy_s(s3, sizeof(b3) / sizeof(TCHAR), p3);
	
//	GetComputerName1();	// complete ANSI function
//	GetComputerName2();	// complete Unicode function
	GetComputerName3(); // either ANSI or Unicode function

	return 0;
}