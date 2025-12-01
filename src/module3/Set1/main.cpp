#include <iostream>
#include <set>
using namespace std;

int main() {
	set<string> s;
	s.insert("Rice Cooker");
	s.insert("Food Blender");
	s.insert("Television");
	set<string>::iterator p = s.find("Television");
	if (p == s.end()) cout << "Not found!" << endl;
	else cout << "Found!" << endl;
	return 0;
}