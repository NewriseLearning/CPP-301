#include <iostream>
#include <exception>

class A {
public:
	A(int n) { std::cout << n << std::endl; }
	A(double d) { std::cout << d << std::endl; }
	A(int n, double d) { std::cout << n << ',' << d << std::endl; }
	A(std::initializer_list<const char*> values) {
		if (values.size() == 0)
			throw std::exception("Not enough initializers.");
		for (auto value : values)
			std::cout << value << std::endl;
	}
};

int main() {
	int v1{};	// initialize to default value for int (0)
	short v2{};	// 0
	bool v3{};	// false
	bool v4{ true };	// true
	auto v5{ 123 };		// 123 (v5 will be int)

	A o1{ 123 };		// A(int n)
	A o2{ 1.99 };		// A(double d)
	A o3{ 123, 1.99 };	// A(int n, double d)

	A o4{ 
		"Hello!", "Goodbye!", "Sayonara!", "Ciao!",
		"Good morning!", "Good day!"
	};

	return 0;
}