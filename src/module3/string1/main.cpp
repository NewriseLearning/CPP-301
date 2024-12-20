#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
//	string s1("Hello!");
	string s1 = "Hello!";
	s1.append(" Goodbye!"); // "Hello! Goodbye!"
	cout << s1.size() << endl;
	cout << s1 << endl;
	s1.replace(7, 7, "Ciao");	// "Hello! Ciao!"
	cout << s1 << endl;
	s1.erase(0, 7);	// "Ciao!"
	cout << s1 << endl;
	s1.insert(0, "Sayonara! "); // "Ciao! Sayonara!"
	cout << s1 << endl;

	wstring s2 = L"Hello!";
	wcout << s2 << endl;

	puts(s1.c_str());	// puts is ANSI so use string object 
	_putws(s2.c_str());	// _putws is Unicode so use wstring object

	sort(s1.begin(), s1.end());
	for (auto c : s1) cout << c << endl;

	return 0;
}