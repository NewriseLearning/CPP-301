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

int main2() {
	deque<const char*> d;
	d.push_front("Hello!");
	d.push_back("Goodbye!");
	cout << d.front() << endl;
	cout << d.back() << endl;
	d.pop_front();
	d.pop_back();
	return 0;
}

template<typename T>
void show_all(T b, T e) {
	while (b != e) cout << *(b++) << endl;
}

#include <algorithm>

int main() {
	vector<int> v(4);
	v[0] = 99;
	v[1] = 62;
	v[2] = 110;
	v[3] = 103;

	v.insert(v.begin(), 160);
	v.insert(v.begin() + 1, 480);
	v.insert(v.end() - 1, 200);
	v.erase(v.begin() + 2);

	sort(v.begin(), v.end());
	if (binary_search(v.begin(),v.end(),110))
		cout << "Found!" << endl;

	reverse(v.begin(), v.end());
//	sort(v.rbegin(), v.rend());
	if (binary_search(v.rbegin(), v.rend(), 110))
		cout << "Found!" << endl;


	
	//vector<int>::iterator b1 = v.begin();
	//vector<int>::iterator e1 = v.end();
	//while (b1 != e1) cout << *(b1++) << endl;
	show_all(v.begin(), v.end());

	rotate(v.begin(), v.begin() + 2, v.end());

	show_all(v.begin(), v.end());

//	for (auto n : v) cout << n << endl;

//	b1 = v.end();
//	e1 = v.begin();
//	while (b1 != e1) cout << *(--b1) << endl;

	//vector<int>::reverse_iterator b2 = v.rbegin();
	//vector<int>::reverse_iterator e2 = v.rend();
	//while (b2 != e2) cout << *(b2++) << endl;
	show_all(v.rbegin(), v.rend());







	return 0;
}

