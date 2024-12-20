#include <iostream>
#include <set>

using namespace std;

int main() {
	// set<string> s;
	multiset<string> s;
	s.insert("Rich Cooker");
	s.insert("Food Blender");
	s.insert("Television");
	s.insert("Television");

	cout << s.size() << endl;

	auto p = s.find("Television");
	if (p == s.end()) cout << "Not found!" << endl;
	else cout << "Found!" << endl;

	return 0;
}
