#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

template<typename T>
void show_all(T b, T e) {
	while (b != e)
		cout << *(b++) << endl;
}


int main1() {
	//vector<int> v(4);
	//v[0] = 10;
	//v[1] = 20;
	//v[2] = 30;
	//v[3] = 40;

	vector<int> v;
	v.push_back(100);	// v[0]
	v.push_back(200);	// v[1]
	v.push_back(300);	// v[2]

	cout << v.size() << endl;	// 3

	v.pop_back();

	cout << v.size() << endl;	// 2

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	cout << v.front() << endl;	// 100
	cout << v.back() << endl;	// 200

	v.front() = 99;
	v.back() = 66;

	cout << v.front() << endl;	// 99
	cout << v.back() << endl;	// 66

	v.clear();
	cout << v.size() << endl;	// 0
	if (v.empty())
		cout << "vector is empty." << endl;
	return 0;
}

int main2() {
	deque<const char*> d;
	d.push_front("Hello!");
	d.push_back("Goodbye!");
	cout << d.front() << endl;
	cout << d.back() << endl;
	d.pop_back();
	d.pop_front();
	return 0;
}

int main() {
	//vector<int> v(4);
	//v[0] = 100;
	//v[1] = 200;
	//v[2] = 300;
	//v[3] = 400;

	vector<int> v;
	v.push_back(100);
	v.push_back(200);
	v.push_back(300);
	v.push_back(400);

//	vector<int>::iterator b1 = v.begin();
//	vector<int>::iterator e1 = v.end();
	auto b1 = v.begin();
	auto e1 = v.end();
	if (b1 == e1) cout << "container is empty.";
	while (b1 != e1) {
	//	cout << *b1 << endl; ++b1;
		cout << *(b1++) << endl;
	}

	/*b1 = v.end();
	e1 = v.begin();
	while (b1 != e1) {
		cout << *(--b1) << endl;
	}*/

	//vector<int>::reverse_iterator b2 = v.rbegin();
	//vector<int>::reverse_iterator e2 = v.rend();
	auto b2 = v.rbegin();
	auto e2 = v.rend();
	if (b2 == e2) cout << "container is empty.";
	while (b2 != e2) {
		cout << *(b2++) << endl;
	}

	cout << "iterator operations:" << endl;

	v.insert(v.begin(), 160);
	v.insert(v.begin() + 1, 480);
	v.insert(v.end() - 1, 240);
	v.erase(v.begin() + 2);

	sort(v.begin(), v.end());
	if (binary_search(v.begin(), v.end(), 240))
		cout << "240 found!" << endl;

	sort(v.rbegin(), v.rend());
	if (binary_search(v.rbegin(), v.rend(), 240))
		cout << "480 found!" << endl;

//	reverse(v.begin(), v.end());
//	sort(v.rbegin(), v.rend());
//	rotate(v.begin(), v.begin() + 2, v.end());
	rotate(v.rbegin(), v.rbegin() + 2, v.rend());
	
	show_all(v.begin(), v.end());
	show_all(v.rbegin(), v.rend());

	cout << "C++ iterator loop:" << endl;
	for (auto n : v)
		cout << n << endl;
}
