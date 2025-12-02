#include <cstdio>
#include <exception>
#include <algorithm>

int a;

int& b() { return a; }
int *c() { return &a; }

const int& d() { return a; }

int main1() {
	printf("a=%ld\n", a);	// 0
	a = 1;					// 1
	printf("a=%ld\n", a);	// 0
	return 0;
}

int main4() {
	b() = 2; printf("b()=%ld\n", a);
	*c() = 3; printf("*c()=%ld\n", a);
	return 0;
}

int main5() {
//	d() = 4;
	printf("%ld\n", d());
	return 0;
}

int e() { return 123; }
int f() { return a;	}

int main6() {
	//e() = 5;
	//f() = 6;
	printf("e()=%ld\n", e());
	printf("f()=%ld\n", f());
	return 0;
}

template<typename T>
class valueable {
private:
	T* m_pValue;
public:
	valueable() : m_pValue{ nullptr } {}
	valueable(T value) { m_pValue = new T; *m_pValue = value; }
	~valueable() { if (m_pValue) delete m_pValue; }
	valueable& operator = (T value) {
		if (m_pValue == nullptr) m_pValue = new T;
		*m_pValue = value; return *this;
	}
	operator const T& () const {
		if (m_pValue == nullptr)
			throw std::exception("Value is null");
		return *m_pValue;
	}
	bool has_value() const {
		return m_pValue != nullptr;
	}
//	valueable(const valueable<T>& obj) = delete;
	valueable(const valueable<T>& obj) : m_pValue{} {
		if (obj.m_pValue != nullptr) {
			m_pValue = new T;
			*m_pValue = *obj.m_pValue;
		}
	#ifdef _DEBUG
		puts("Copy constructor called.");
	#endif
	}
	//valueable(valueable<T>&& obj) : m_pValue(obj.m_pValue) {
	//if (m_pValue) obj.m_pValue = nullptr;

	//#ifdef _DEBUG
	//	puts("Move constructor called.");
	//#endif
	//}

	valueable(valueable<T>&& obj) noexcept : m_pValue(nullptr) {
		std::swap(m_pValue, obj.m_pValue);
	#ifdef _DEBUG
		puts("Move constructor called.");
	#endif
	}

};

void show_value(const valueable<int>& v) {
	if (v.has_value()) {
		int n = v;
		printf("value = %ld\n", n);
	}
}

int main7() {
	valueable<int> v1;	// nullptr
//	valueable<int> v2(123);	// 123
//	valueable<int> v3 = 999;	// 999
	valueable<int> v2{ 123 };	// 123
	valueable<int> v3{ 999 };	// 999

	show_value(v1);
	show_value(v2);
	show_value(v3);

	v2 = v2 + 17;	// 123 + 17 
	show_value(v2);

	v3 = v3 - 99;
	show_value(v3);

	show_value(666);

	return 0;
}

valueable<int> get_valueable(int n) {
	valueable<int> v(n);
	return v;
}

int main8() {
	valueable<int>* v1 = new valueable<int>(999);
	valueable<int>* v2 = new valueable<int>(*v1);

	show_value(*v1); delete v1;
	show_value(*v2); delete v2;
	return 0;
}

int main() {
	auto v = get_valueable(666);
	show_value(666);

	valueable<int> v1(66);
	valueable<int> v2(std::move(v1));
	if (v1.has_value()) printf("v1=%d\n", (int)v1);
	if (v2.has_value()) printf("v2=%d\n", (int)v2);
}

