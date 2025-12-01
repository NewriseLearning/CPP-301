#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
//	string s1("Hello!");
	string s1 = "Hello!";
	s1.append(" Goodbye!");
	cout << s1.size() << endl;
	s1.replace(7, 7, "Ciao");
	s1.erase(0, 7);
	s1.insert(0, "Sayonara! ");
	cout << s1 << endl;
	puts(s1.c_str());

//	wstring s2(L"Hello!");
	wstring s2 = L"Hello!";
	wcout << s2 << endl;
	_putws(s2.c_str());

	return 0;
}