#include <iostream>
#include <vector>

using namespace std;


int main1() {
	vector<int> v;
//	vector<int> v(4);
	v.push_back(100);
	v.push_back(200);
	v.push_back(300);
	cout << v.size() << endl;
	v.pop_back();
	cout << v.size() << endl;
	for (size_t i = 0; i < v.size(); i++) cout << v[i] << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;
	v.front() = 99;
	v.back() = 66;
	for (size_t i = 0; i < v.size(); i++) cout << v[i] << endl;
	v.clear();
//	if (v.size() == 0) cout << "No elements" << endl;
	if (v.empty()) cout << "No elements" << endl;
	return 0;
}

#include <deque>

int main() {
	deque<const char*> d;
	d.push_front("Hello!");
	d.push_back("Goodbye!");
	cout << d.front() << endl;
	cout << d.back() << endl;
	d.pop_front();
	d.pop_back();
	return 0;
}