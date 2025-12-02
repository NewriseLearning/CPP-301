#include <thread>
#include <future>
#include <iostream>

using namespace std;

promise<int> p1;

void setValue(int min, int max) {
	srand(time(0));
	this_thread::sleep_for(chrono::seconds{ 4 });
	p1.set_value((rand() % (max - min + 1)) + min);
}

int main() {
	thread t1{ setValue, 1, 6 };
	future<int> f1 = p1.get_future();
	int n1 = f1.get();	// wait for promise to be satisfied
	cout << n1 << endl;
	t1.join();
	return 0;
}