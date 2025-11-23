#include <iostream>
using namespace std;

// typedef int (*myfuncptr)(int x, int y);

//int add(int x, int y) { return x + y; }
//int sub(int x, int y) { return x - y; }
//int mul(int x, int y) { return x * y; }

//void display(myfuncptr p) {
////	cout << (*p)(10, 20) << endl;
//	cout << p(10, 20) << endl;
//}

void display(int f(int x, int y)) {
	cout << f(10, 20) << endl;
}

int main() {
	// myfuncptr p;
	//p = add; cout << (*p)(10, 20) << endl;	// 30
	//p = sub; cout << (*p)(10, 20) << endl;	// -10
	//p = mul; cout << (*p)(10, 20) << endl;	// 200
	//p = add; cout << p(10, 20) << endl;	// 30
	//p = sub; cout << p(10, 20) << endl;	// -10
	//p = mul; cout << p(10, 20) << endl;	// 200
	//display(add);	// passing function pointer
	//display(sub);	// passing function pointer
	//display(mul);	// passing function pointer
	//	lambda expressions
	//display([](int x, int y) -> int { return x + y; });
	//display([](int x, int y) -> int { return x - y; });
	//display([](int x, int y) -> int { return x * y; });
	//auto add = [](int x, int y) -> int { return x + y; };
	//auto sub = [](int x, int y) -> int { return x - y; };
	//auto mul = [](int x, int y) -> int { return x * y; };
	//auto add = [](int x, int y) { return x + y; };
	//auto sub = [](int x, int y) { return x - y; };
	//auto mul = [](int x, int y) { return x * y; };
	int v = 0;
	auto add = [&v](int x, int y) { return v += x + y; };
	auto sub = [&v](int x, int y) { return v += x - y; };
	auto mul = [&v](int x, int y) { return v += x * y; };

	cout << add(10, 20) << endl;	// v = v(0) + 10 + 20 = 30
	cout << sub(10, 20) << endl;	// v = v(30) + 10 - 20 = 20
	cout << mul(10, 20) << endl;	// v = v(20) + 10 * 20 = 220

	cout << v << endl;

	//display(add);
	//display(sub);
	//display(mul);

	int a = 10;
	int b = 20;
	//	capture all locals by value (can access, cannot change)
	auto l1 = [=]() { cout << (a * b) << endl; };

	//	capture all locals by reference (can access and can change)
	auto l2 = [&]() { a *= b; b *= 2; cout << a << ',' << b << endl; };

	// selective capture (a by value, b by reference)
	auto l3 = [a, &b] { b = a * 10; cout << a << ',' << b << endl; };

	// selective capture (others by reference, a by value)
	auto l4 = [&, a] { b = a * 10; cout << a << ',' << b << endl; };

	// selective capture (others by value, b by reference)
	auto l5 = [=, &b] { b = a * 10; cout << a << ',' << b << endl; };

	l1();
	l2();
	l3();
	l4();
	l5();

	return 0;
}