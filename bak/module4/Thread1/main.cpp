#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m1;

//void display(const string& message) {
//	m1.lock(); cout << message << " is running..." << endl; m1.unlock();
//	this_thread::sleep_for(chrono::seconds{ 4 });
//	m1.lock(); cout << message << " is completed." << endl; m1.unlock();
//}

atomic_int tcount = 0;	// thread-safe (can be updated from multiple threads at the same time)

void display(const string& message) {
	++tcount;
	{
		lock_guard<mutex> g(m1);
		cout << message << " is running..." << endl;
	}
	this_thread::sleep_for(chrono::seconds{ 4 });
	{
		lock_guard<mutex> g(m1);
		cout << message << " is completed." << endl;
	}
	--tcount;
}

int main() {
	thread t1{ display, "Thread #1"};
	thread t2{ display, "Thread #2" };
	thread t3{ display, "Thread #3" };
	{
		lock_guard<mutex> g(m1);
		cout << "Thread #1 id = " << t1.get_id() << endl;
		cout << "Thread #2 id = " << t2.get_id() << endl;
		cout << "Thread #3 id = " << t3.get_id() << endl;
	}
	t1.join(); t2.join(); t3.join();
	cout << "Thread count:" << tcount << endl;
	return 0;
}