#include <iostream>
#include <vector>
#include <deque>

using namespace std;

template<typename T>
class List0 : public vector<T> {

};

// List1 is a vector double container
class List1 : public vector<double> {
public:
	List1() {
		push_back(1.1);
		push_back(2.2);
		push_back(3.3);
	}
	double Sum() {
		double total = 0;
		for (auto value : *this)
			total += value;
		return total;
	}
};

// List2 aggregates a vector double container
class List2 {
private:
	vector<double> m_v;
public:
	List2() {
		m_v.push_back(1.1);
		m_v.push_back(2.2);
		m_v.push_back(3.3);
	}
	double Sum() {
		double total = 0;
		for (auto value : m_v)
			total += value;
		return total;
	}
	void Push(double v) {
		m_v.push_back(v);
	}
	//void Clear() {
	//	m_v.clear();
	//}
};

int main() {
//	List0<int> t;
	List1 l1;
	List2 l2;
	l1.push_back(4.4);
	l2.Push(4.4);
	cout << l1.Sum() << endl;
	cout << l2.Sum() << endl;
	return 0;
}