#include <iostream>
using namespace std;

int main1() {
	cout << "\"C:\\CPP-301\\doc\\01.pdf\"" << endl;
	cout << R"("C:\CPP-301\doc\01.pdf")" << endl;	// raw string
	return 0;
}

#include <regex>

int main2() {
	string zipcode;
//	regex rx(R"([0-9][0-9][0-9][0-9][0-9])");
//	regex rx(R"([0-9]{5})");
	regex rx(R"(\d{5})");
	do {
		cout << "Enter zip code:"; cin >> zipcode;
		if (regex_match(zipcode, rx)) break;
		cout << "Invalid zip code. Please re-enter." << endl;
	} while (true);
	cout << "Zipcode:" << zipcode << endl;
	return 0;
}

int main3() {
	smatch data;
//	to resolve a bug with regular expression in VS2019
//	add an extra character after input
//	match the extra character in your pattern
//	it will be removed in the result
	regex rx(R"((\d{3})/(\d{2})/(\d{4}|\d{2}))");
	do {
		string date;
		cout << "Enter date (dd/mm/yyyy):"; cin >> date; 
		date.insert(0, 1, '0');	// insert an extra character
		if (regex_search(date, data, rx)) break;
		cout << "Invalid date. Please re-enter." << endl;
	} while (true);
	cout
		<< data[0] << endl	// default group
		<< data[1] << endl	// day
		<< data[2] << endl	// month
		<< data[3] << endl; // year
	return 0;
}

int main4() {
	string text("11 22 33 44 55 66");
	regex rx(R"(\d+)");
	auto b = sregex_iterator(text.begin(), text.end(), rx);
	auto e = sregex_iterator();
	while (b != e) {
		smatch m = *(b++);
		cout << m.str() << endl;
	}
	return 0;
}

int main() {
	string text("01/01/1900 06/10/1967 23/12/2024");
	regex rx(R"((\d{2})/(\d{2})/(\d{4}|\d{2}))");
	auto b = sregex_iterator(text.begin(), text.end(), rx);
	auto e = sregex_iterator();
	while (b != e) {
		smatch m = *(b++);
		cout
			<< m[0] << ','		// default group (entire date)
			<< m[1] << ','		// day group
			<< m[2] << ','		// month group
			<< m[3] << endl;	// year group
	}
	return 0;
}

