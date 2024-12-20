#include <iostream>
#include <vector>

using namespace std;

// List1 is a double vector
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

// List2 contains a double vector
class List2 {
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
	void push_back(double v) {
		m_v.push_back(v);
	}
	size_t size() {
		return m_v.size();
	}
};

int main() {
	List1 l1;
	List2 l2;
	l1.push_back(4.4);
	l2.push_back(4.4);
	cout << l1.Sum() << endl;
	cout << l2.Sum() << endl;
	return 0;
}
