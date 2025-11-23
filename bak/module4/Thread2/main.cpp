#include <iostream>
#include <thread>
#include <future>
#include <ctime>

using namespace std;

promise<int> p1;
//
//void setValue(int min, int max) {
//	this_thread::sleep_for(chrono::seconds{ 4 });
//	p1.set_value();
//}

int getValue(int min, int max) {
	this_thread::sleep_for(chrono::seconds{ 4 });
	return (int)((double)rand() * max / RAND_MAX + min);
}

//int main() {
//	auto seed = (int)time(nullptr);
//	cout << seed << endl;
//	srand(seed);
//	thread t1{ setValue, 1, 6 };
//	future<int> f1 = p1.get_future();
//	int n1 = f1.get();
//	cout << n1 << endl;
//	t1.join();
//	return 0;
//}

int main() {
	int n1 = getValue(1, 6);	// synchronous call
	cout << n1 << endl;

	future<int> f1 = async(getValue, 1, 6);	// asynchronous call
	n1 = f1.get();	// wait for promised value
	cout << n1 << endl;

}


