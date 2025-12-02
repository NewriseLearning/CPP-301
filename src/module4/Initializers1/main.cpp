#include <iostream>

class A {
public:
	A(int n) { std::cout << n << std::endl; }
	A(double d) { std::cout << d << std::endl; }
	A(int n, double d) { std::cout << n << ',' << d << std::endl; }
};

int main() {
	int v1{};
	short v2{};
	bool v3{};
	bool v4{ true };
	auto v5{ 123 };

	A o1{ 123 };
	A o2{ 1.99 };
	A o3{ 123, 1.99 };

	return 0;
}

