
class A {
private:
	int m_value1;
public:
	A() : m_value1{} { }
	virtual void func1(int v) { m_value1 = v; }
};

class B : public A {
private:
	int m_value2;
public:
	B() : m_value2() { }
	void funcA(int v) { func1(v * 2); }
	virtual void func2(int v) { m_value2 = v; }
};

class C : public B {
private:
	int m_value3;
public:
	C() : m_value3{} { }
	virtual void func3(int v) { m_value3 = v; }
};

class D {
private:
	int m_value1;
	int m_value2;
	int m_value3;
public:
	D() { m_value1 = m_value2 = m_value3 = 0; }
	virtual void func4(int v1, int v2, int v3) {
		m_value1 = v1;
		m_value2 = v2;
		m_value3 = v3;
	}
};

#include <typeinfo>
#include <iostream>

using namespace std;

int main1() {
	A* p1 = new B();
	A* p2 = new C();
	cout << typeid(p1).name() << endl;	// A*
	cout << typeid(p2).name() << endl;	// A*
	cout << typeid(*p1).name() << endl;	// B
	cout << typeid(*p2).name() << endl;	// C

	if (typeid(p1) == typeid(p2))
		cout << "Pointers are the same." << endl;
	if (typeid(*p1) != typeid(*p2))
		cout << "Objects are different." << endl;

	if (typeid(*p1) == typeid(B))
		cout << "p1 points to a B object." << endl;
	if (typeid(*p2) != typeid(B))
		cout << "p2 does not points to a B object." << endl;
	if (typeid(*p2) == typeid(C))
		cout << "p2 points to a C object." << endl;

	const type_info& i1 = typeid(*p1);
	const type_info& i2 = typeid(*p2);

	if (i1.before(i2)) cout << "B comes before C." << endl;
	if (!i2.before(i1)) cout << "C does not come before B." << endl;

	const type_info& i3 = typeid(A);
	if (i3.before(i1)) cout << "B is fully compatible to A." << endl;
	if (i3.before(i2)) cout << "C is fully compatible to A." << endl;
	return 0;
}

int main() {
	A* p1 = new A();
	A* p2 = new B();
	A* p3 = new C();
	B* p4 = new C();
	D* p5 = new D();
	
//	// partly compatible
//	B* p6 = (B *)p1;	// p1 is pointing to an A object, not an B object
//	p6->funcA(66);
////	p6->func2(99);
//
//	// totally incompatible
//	B* p7 = (B*)p5;
//	p7->funcA(66);

	// C++ casting operators
	//B* p6 = reinterpret_cast<B*>(p1);
	//B* p7 = reinterpret_cast<B*>(p5);

//	B* p6 = static_cast<B*>(p1);
//	B* p7 = static_cast<B*>(p8);

	B* p6 = dynamic_cast<B*>(p3);
	B* p7 = dynamic_cast<B*>(p5);

	if (p6 != nullptr) cout << "p6 is compatible to B" << endl;
	if (p7 == nullptr) cout << "p7 is not compatible to B" << endl;

	const int n1 = 66;
	const_cast<int&>(n1) = 99;
	cout << const_cast<int&>(n1) << endl;
}