#include <regex>
#include <iostream>

using namespace std;

int main1() {
	cout << "C:\\CPPDEV\\DOC\\01.ODT" << endl;
	cout << R"(C:\CPPDEV\DOC\01.ODT)" << endl;
	return 0;
}

int main2() {
	string zipcode;
	regex rx(R"(\d{5})");
	do {
		cout << "Enter zip code:"; cin >> zipcode;
		if (regex_match(zipcode, rx)) break;
		cout << "Invalid zip code. Please reenter." << endl;
	} while (true);
	cout << "Zipcode:" << zipcode << endl;
	return 0;
}

int main3() {
	smatch data;
	regex rx(R"((\d{2})/(\d{2})/(\d{4}|\d{2}))");
	do {
		string date;
		cout << "Enter date (dd/mm/yyyy):"; cin >> date;
		if (regex_search(date, data, rx)) break;
		cout << "Invalid date. Please reenter." << endl;

	} while (true);
	cout
		<< data[0] << endl
		<< data[1] << endl
		<< data[2] << endl
		<< data[3] << endl;
	return 0;
}

int main() {
	string text("11,22,33,44,55,66");
	regex rx(R"(\d+)");
	auto b = sregex_iterator(text.begin(), text.end(), rx);
	auto e = sregex_iterator();
	while (b != e) {
		smatch m = *(b++);
//		cout << m[0] << endl;
		cout << m.str() << endl;
	}
	return 0;
}