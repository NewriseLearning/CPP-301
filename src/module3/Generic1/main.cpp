#include <iostream>

//void swap_vars(int& v1, int& v2) {
//	int vt = v1; v1 = v2; v2 = vt;
//}
//
//void swap_vars(double& v1, double& v2) {
//	double vt = v1; v1 = v2; v2 = vt;
//}
//
//void swap_vars(const char *& v1, const char *& v2) {
//	const char * vt = v1; v1 = v2; v2 = vt;
//}

template<typename T>
void swap_vars(T& v1, T& v2) {
	T vt = v1; v1 = v2; v2 = vt;
}

//int max_value(int a, int b) {
//	return a > b ? a : b;
//}

template<typename X>
X max_value(X a, X b) {
	return a > b ? a : b;
}

// const char * does not support > operator
// we can only replace standard operators in C# not in C++
// so we need to overload the generic function
// specifically to support const char *
const char* max_value(const char* a, const char* b) {
	return strcmp(a, b) > 0 ? a : b;
}

template<typename X, typename Y>
X add_any(X arg1, Y arg2) {
	return (X)(arg1 + (X)arg2);
}

template<typename T, int SIZE>
void display_array(T (&a)[SIZE]) {
	for (int i = 0; i < SIZE; i++)
		std::cout << a[i] << std::endl;
}

int main1() {
	int n1 = 99, n2 = 66;
	double d1 = 1.99, d2 = 99.1;
	const char *s1 = "Hello!", *s2 = "Goodbye!";
	char c1 = 'A', c2 = 'Z';
	swap_vars(n1, n2); // swap_vars<int>(n1, n2);
	swap_vars(d1, d2); // swap_var<double>(d1, d2);
	swap_vars(s1, s2); // swap_vars<const char *>(s1, s2);
	swap_vars(c1, c2); // swap_vars<char>(c1, c2);
	std::cout << n1 << ',' << n2 << std::endl;
	std::cout << d1 << ',' << d2 << std::endl;
	std::cout << s1 << ',' << s2 << std::endl;
	std::cout << c1 << ',' << c2 << std::endl;

	std::string sa = "Hello!";
	std::string sb = "Goodbye!";

	std::cout << max_value(sa, sb) << std::endl;

	std::cout << max_value(66, 99) << std ::endl;
	std::cout << max_value(1.99, 99.1) << std::endl;
	std::cout << max_value('A', 'Z') << std::endl;
	std::cout << max_value("Goodbye!","Hello!") << std::endl;

	std::cout << add_any('A', 2) << std::endl;
	std::cout << add_any(10, 69.99) << std::endl;

	return 0;
}

int main() {
	main1();

	int a1[] = { 10, 20, 30, 40, 50 };
	double a2[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	char a3[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	//display_array<int, 5>(a1);
	//display_array<double, 6>(a2);
	//display_array<char, 7>(a3);
	display_array(a1);
	display_array(a2);
	display_array(a3);
}