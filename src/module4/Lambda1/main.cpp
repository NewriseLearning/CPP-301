#include <iostream>
using namespace std;

// typedef int (*myfuncptr)(int, int);
// typedef int myfuncptr(int, int);

//int add(int x, int y) { return x + y; }
//int sub(int x, int y) { return x - y; }
//int mul(int x, int y) { return x * y; }

// void display(myfuncptr p) {
void display(int p(int,int)) {
	cout << p(10, 20) << endl;
}

int main() {
	int v{};

	auto add = [&v](int x, int y)->int {  return v += x + y; };
	auto sub = [&v](int x, int y) { return v += x - y; };
	auto mul = [&v](int x, int y) { return v += x * y; };

//	myfuncptr *p;
//	p = add; cout << (*p)(10, 20) << endl;	// 30
//	p = sub; cout << (*p)(10, 20) << endl;	// -10
//	p = mul; cout << (*p)(10, 20) << endl;	// 200
	//auto p = add; cout << p(10, 20) << endl;	// 30
	//p = sub; cout << p(10, 20) << endl;	// -10
	//p = mul; cout << p(10, 20) << endl;	// 200
//	display(add);
//	display(sub);
//	display(mul);
//	display([](int x, int y) { return x + y; });
//	display([](int x, int y) { return x - y; });
//	display([](int x, int y) { return x * y; });
	cout << add(10, 20) << endl;
	cout << sub(10, 20) << endl;
	cout << mul(10, 20) << endl;
	cout << v << endl;
	return 0;
}