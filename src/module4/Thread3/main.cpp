#include <thread>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <future>

using namespace std;

int getValue(int min, int max) {
	this_thread::sleep_for(chrono::seconds{ 4 });
	srand(time(0));
	return ((rand() % (max - min + 1)) + min);
}

int main() {
	int n1 = getValue(1, 6); // synchronous call
	cout << n1 << endl;
	future<int> f1 = async(getValue, 1, 6); // asynchronous call
	n1 = f1.get();	// waiting for the result
	cout << n1 << endl;
	return 0;
}
