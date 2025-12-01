#include "my_templates.h"
#include <iostream>


void func1(const char* value = nullptr) {
	if (value == nullptr) value = "Hello!";
	std::cout << value << std::endl;
}

void func2(nullable<int> value = nullptr) {
	if (value == nullptr) value = 123;
	std::cout << value << std::endl;
}

int main1() {
	CStack<int> s1(1000);
//	CStack<int> s1;
	for (int index = 0; index < 1000; index++) s1.Push(index);
	while (!s1.Empty()) std::cout << s1.Pop() << std::endl;
	return 0;
}

int main() {
	func1(nullptr);	// Hello!
	func1("Goodbye!"); // Goodbye!
	func1(); // Hello!

	func2(nullptr);	// 123
	func2(256);		// 256
	func2();		// 123

	return 0;
}
