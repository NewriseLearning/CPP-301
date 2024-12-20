#include "nullable.h"
#include <iostream>

void show_message(const char* message = nullptr) {
	if (message == nullptr) message = "Hello!";
	std::cout << message << std::endl;
}

void show(nullable<int> value = nullptr) {
	if (value == nullptr) value = 123;
	std::cout << value << std::endl;
}

int main1() {
	show();
	show(nullptr);
	show(999);
	show_message();
	show_message(nullptr);
	show_message("Goodbye!");
	return 0;
}

void func1(nullable<int> obj) {
	std::cout << "Received nullable<int> object." << std::endl;
}

void func2(int value) {
	std::cout << "Received int value." << std::endl;
}

int main() {
	func1(666);	// nullable<int> obj(666)
	func2(999);
	func2(nullable<int>(333));  // nullable<int>::int() { return m_value; }


	nullable<int> n1;			// nullable<int> n1();
	nullable<int> n2 = nullptr;	// nullable<int> n2(nullptr);
	nullable<int> n3 = 999;		// nullable<int> n3(999);

	if (n1.hasValue()) std::cout << "n1:" << (int)n1 << std::endl;
	if (n2.hasValue()) std::cout << "n2:" << (int)n2 << std::endl;
	if (n3.hasValue()) std::cout << "n3:" << (int)n3 << std::endl;

	if (n1 == nullptr) std::cout << "n1 is null" << std::endl;
	if (n2 == nullptr) std::cout << "n2 is null" << std::endl;
	if (n3 == nullptr) std::cout << "n3 is null" << std::endl;

}
