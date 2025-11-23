#include <iostream>

// this should be declared as it will be used
// by the variadic template
void out_all() {
	std::cout << "<-end->" << std::endl;
}

template<typename T, typename... Ts>
void out_all(const T& head, const Ts&... rest) {
	std::cout << head << std::endl;
	out_all(rest...);
}

int main() {
	out_all();
	out_all(10);
	out_all(10, 20);
	out_all(10, 20, 30, 40, 50, 60);
	out_all('A', 10, 1.1, "Hello!");
	return 0;
}
