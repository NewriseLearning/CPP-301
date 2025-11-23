#include <iostream>

template<typename T>
void swap_vars(T& v1, T& v2) {
	T vt = v1; v1 = v2; v2 = vt;
}

//template<typename T>
//T max_value(T a, T b) { return a > b ? a : b; }
//
//template<typename T>
//T min_value(T a, T b) { return a < b ? a : b; }


template<typename T>
struct values {
	static T max(T a, T b) { return a > b ? a : b; }
	static T min(T a, T b) { return a < b ? a : b; }
};

template<typename X, typename Y>
X add_any(X arg1, Y arg2) {
	return (X)(arg1 + (X)arg2);
}

template<typename T, int SIZE>
void display_array(T(&a)[SIZE]) {
	for (int i = 0; i < SIZE; i++)
		std::cout << a[i] << std::endl;
}

//void swap_vars(int& v1, int& v2) {
//	int vt = v1; v1 = v2; v2 = vt;
//}
//
//void swap_vars(double& v1, double& v2) {
//	double vt = v1; v1 = v2; v2 = vt;
//}
//
//void swap_vars(const char*& v1, const char*& v2) {
//	const char* vt = v1; v1 = v2; v2 = vt;
//}

int main1() {
	int n1 = 66, n2 = 99;
	double d1 = 1.99, d2 = 99.1;
	const char* s1 = "Hello!", *s2 = "Goodbye!";
	char c1 = 'A', c2 = 'Z';
	bool b1 = false, b2 = true;
	swap_vars(n1, n2);	// swap_vars<int>(n1, n2);
	swap_vars(d1, d2);	// swap_vars<double>(d1, d2);
	swap_vars(s1, s2);	// swap_vars<const char *>(s1, s2);
	swap_vars(c1, c2);	// swap_vars<char>(c1, c2);
	swap_vars(b1, b2);	// swap_vars<bool>(b1, b2);
	std::cout
		<< n1 << ',' << n2 << std::endl
		<< d1 << ',' << d2 << std::endl
		<< s1 << ',' << s2 << std::endl
		<< c1 << ',' << c2 << std::endl
		<< b1 << ',' << b2 << std::endl;
	std::cout
		<< values<int>::max(n1, n2) << ','
		<< values<int>::min(n1, n2)
		<< std::endl
		<< values<double>::max(d1, d2) << ','
		<< values<double>::min(d1, d2)
		<< std::endl
		<< values<char>::max(c1, c2) << ','
		<< values<char>::min(c1, c2)
		<< std::endl;
	std::cout
		<< add_any(66, 1.99) << std::endl
		<< add_any(1.99, 99) << std::endl
		<< add_any('A', 2) << std::endl
		<< add_any(3, 'E') << std::endl;
	return 0;
}

int main() {
	int a1[] = { 10, 20, 30, 40, 50 };
	double a2[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	char a3[] = { 'A' , 'B', 'C', 'D', 'E', 'F' };
	display_array(a1);	// display_array<int,5>(a1);
	display_array(a2);	// display_array<double,7>(a2);
	display_array(a3);	// display_array<char,6>(a3);
	return 0;
}