#include <iostream>
#include <map>

using namespace std;

typedef multimap<int, string> ProductMap;
typedef pair<int, string> Product;
typedef ProductMap::iterator ProductPtr;

int main() {
//	multimap<int, string> m;
	ProductMap m;
	//m.insert(pair<int, string>(100, "Can of coke"));
	//m.insert(pair<int, string>(200, "Bottle of ketchup"));
	//m.insert(pair<int, string>(300, "Pack of noodles"));
	//m.insert(pair<int, string>(300, "Pack of Maggi noodles"));
	m.insert(Product(100, "Can of coke"));
	m.insert(Product(200, "Bottle of ketchup"));
	m.insert(Product(300, "Pack of noodles"));
	m.insert(Product(300, "Pack of Maggi noodles"));

	cout << m.size() << endl;

//	multimap<int, string>::iterator p = m.find(200);
//	auto p = m.find(300);
//	auto u = m.upper_bound(300);
	ProductPtr p = m.find(300);
	ProductPtr u = m.upper_bound(300);
	if (p == m.end()) {
		cout << "Item not found!" << endl;
		return 0;
	}

	while (p != u) {
		cout << "Item found!" << endl;
		cout << "Key:" << p->first << endl;
		cout << "Value:" << p->second << endl;
		++p;
	}

	return 0;
}