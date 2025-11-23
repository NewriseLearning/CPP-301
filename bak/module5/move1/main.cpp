#include <cstdio>
#include <exception>
#include <memory>

int a;	// variable is a l-value

// functions can also be l-values
int& b() { return a; }	// return reference of a
int* c() { return &a; }	// return pointer to a
const int& d() { return a; }	// return constant reference of a

int main2() {
	b() = 2;	printf("b()=%ld\n", a);
	*c() = 3;	printf("*c()=%ld\n", a);
//	d() = 4;	// cannot compile because constant cannot be changed
	printf("d()=%ld\n", d());
	return 0;
}

// functions can be r-value
int e() { return 123; }	// return a copy of 123.
int f() { return a; }	// return a copy of a's value.

int main3() {
//	e() = 5; 
//	f() = 6;
	printf("e()=%ld\n", e());
	printf("f()=%ld\n", f());
	return 0;
}

template<typename T>
class valueable {
private:
	T* m_pValue;
public:
	valueable() : m_pValue(nullptr) { }
	valueable(T value) { m_pValue = new T; *m_pValue = value; }
	~valueable() { if (m_pValue) delete m_pValue; }

	//	valueable(const valueable& obj) = default;
	//valueable(const valueable& obj) {
	//	throw std::exception("Copy not allowed.");
	//}
	//valueable(const valueable<T>& obj) = delete;

	valueable(const valueable<T>& obj) : m_pValue(nullptr) {
		if (obj.m_pValue != nullptr) {
			m_pValue = new T; // allocate dynamic memory for the copy
			*m_pValue = *obj.m_pValue; // store a copy of the original value
		}
		puts("Copy constructor called.");
	}

	valueable(valueable<T>&& obj) noexcept : m_pValue(nullptr){
	//	T* ptr = obj.m_pValue; obj.m_pValue = m_pValue; m_pValue = ptr;
		std::swap(m_pValue, obj.m_pValue);
		puts("Move constructor called.");
	}

	valueable& operator =(T value) {
		if (m_pValue == nullptr) m_pValue = new T;
		*m_pValue = value; return *this;
	}
	operator const T& () const {
		if (m_pValue == nullptr)
			throw std::exception("Value is null.");
		return *m_pValue;
	}
	bool has_value() const {
		return m_pValue != nullptr;
	}
};

void show_value(const valueable<int>& v) {
	if (v.has_value()) {
		int n = v; // object is compatible with int
		printf("value = %ld\n", n);
	}
}

valueable<int> get_valueable(int n) {
	valueable<int> v(n);
	return v;
}

int main() {
	valueable<int> v1(66);
	valueable<int> v2(std::move(v1));
	if (v1.has_value()) printf("v1=%d\n", (int)v1);
	if (v2.has_value()) printf("v2=%d\n", (int)v2);
	return 0;
}

int main6() {
	auto v = get_valueable(666);	// getting a copy
	show_value(v);					// accessing the copy
	return 0;
}

int main5() {
	valueable<int>* v1 = new valueable<int>(999);	// original
	valueable<int>* v2 = new valueable<int>(*v1);	// copy
//	valueable<int>* v2 = new valueable<int>((int)*v1);	// copy value

	*v1 = *v1 + 1;
	*v2 = *v2 - 1;

	// pointers converted to references
	valueable<int>& r1 = *v1; show_value(r1);
	valueable<int>& r2 = *v2; show_value(r2);

	// objects/references convertered to pointers
	valueable<int>* p1 = &r1; show_value(*p1);
	valueable<int>* p2 = &r2; show_value(*p2);

	show_value(*v1); delete v1;
	show_value(*v2); delete v2;

	return 0;
}

int main4() {
	valueable<int> v1; // object without value
	valueable<int> v2(123); // object with value 123
	valueable<int> v3 = 999; // int 999 is compatible with object
	int n1 = v3;	// object is compatible to int
	show_value(v1); // no value
	show_value(v2); // 123
	show_value(v3); // 999
	show_value(999);	// valuable<int> v(999);

	v2 = v2 + 17; show_value(v2);
	v3 = v3 - 99; show_value(v3);

	return 0;
}



int main1() {
	printf("a=%ld\n", a);
	a = 1;	// modify a
	printf("a=%ld\n", a);
	return 0;
}