#include <iostream>
#include <map>

using namespace std;

typedef map<int, string> ProductMap;
typedef map<int, string>::iterator ProductPtr;
typedef pair<int, string> Product;

int main() {
	//map<int, string> m;
	//m.insert(pair<int, string>(100, "Can of Coke"));
	//m.insert(pair<int, string>(200, "Bottle of Ketchup"));
	//m.insert(pair<int, string>(300, "Pack of Noodles"));
	//m.insert(pair<int, string>(300, "Maggi Mee"));

	ProductMap m;
	m.insert(Product(100, "Can of Coke"));
	m.insert(Product(200, "Bottle of Ketchup"));
	m.insert(Product(300, "Pack of Noodles"));
	m.insert(Product(300, "Maggi Mee"));

	cout << m.size() << endl;

	ProductPtr p = m.find(300);
	if (p == m.end()) {
		cout << "Item not found!" << endl;
		return 0;
	}

	cout << "Key:" << p->first << endl;
	cout << "Value:" << p->second << endl;

	return 0;
}