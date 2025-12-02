
class A {
private:
	int m_value1;
public:
	A() : m_value1{} {}
	virtual void func1(int v) { m_value1 = v; }
};

class B : public A {
private:
	int m_value2;
public:
	B() : m_value2{} {}
	virtual void func2(int v) { m_value2 = v; }
	void funcA(int v) { func1(v * 2); }
};

class C : public B {
private:
	int m_value3;
public:
	C() : m_value3{} {}
	virtual void func3(int v) { m_value3 = v; }
};

class D {
private:
	int m_value1;
	int m_value2;
	int m_value3;
public:
	D() : m_value1{}, m_value2{}, m_value3{} {}
	//D() {
	//	m_value1 = m_value2 = m_value3 = 0;
	//}
	virtual void f4(int v1, int v2, int v3) {
		m_value1 = v1;
		m_value2 = v2;
		m_value3 = v3;
	}
};

#include <typeinfo>
#include <iostream>

using namespace std;

int main2() {
	A* p1 = new B();
	A* p2 = new C();
	cout << typeid(p1).name() << endl;
	cout << typeid(p2).name() << endl;
	cout << typeid(*p1).name() << endl;
	cout << typeid(*p2).name() << endl;
	if (typeid(p1) == typeid(p2))
		cout << "Pointers are same type." << endl;
	if (typeid(*p1) != typeid(*p2))
		cout << "Objects are different type." << endl;
	if (typeid(*p1) == typeid(B))
		cout << "p1 is pointing to B object." << endl;
	if (typeid(*p2) != typeid(B))
		cout << "p2 is not pointing to B object." << endl;
	if (typeid(*p2) == typeid(C))
		cout << "p2 is pointing to C object." << endl;

	const type_info& i1 = typeid(*p1);	// type info for class B
	const type_info& i2 = typeid(*p2);	// type info for class C

	if (i1.before(i2)) cout << "B comes before C." << endl;
	if (!i2.before(i1)) cout << "C does not come before B." << endl;

	const type_info& i3 = typeid(A);
	if (i3.before(i1)) cout << "B is fully compatible to A." << endl;
	if (i3.before(i2)) cout << "C is fully compatible to A and B." << endl;
	return 0;
}

int main3() {
	A* p1 = new A();	// fully compatible non-abstract
	A* p2 = new B();	// B is compatible to A
	A* p3 = new C();	// C is compatible to A
	B* p4 = new C();	// C is compatible to B
	D* p5 = new D();	// not compatible to A,B or C

//	B* p6 = reinterpret_cast<B *>(p1);		// A is only partly compatible to B
//	B* p6 = static_cast<B*>(p1);		// A is only partly compatible to B
	B* p6 = dynamic_cast<B*>(p1);		// A is only partly compatible to B
	if (!p6) cout << "Not compatible to B*" << endl;
	else p6->funcA(123);// works
//	p6->func2(123);			// crash

//	B* p7 = reinterpret_cast<B *>(p5);		// D is fully incompatible to B
//	B* p7 = static_cast<B*>(p5);		// D is fully incompatible to B
	B* p7 = dynamic_cast<B*>(p5);		// D is fully incompatible to B
	if (!p7) cout << "Not compatible to B*" << endl;
	else p7->funcA(66);		// definitely crash


	return 0;
}

int main() {
	const volatile int n1 = 66;
	const_cast<int&>(n1) = 99;

	cout << n1 << endl;	// still 66 from cache
	cout << const_cast<int&>(n1) << endl;	// 99

	return 0;
}
