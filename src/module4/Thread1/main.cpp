#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

mutex m1;

atomic<int> tcount;

void display(const string& message) {
	++tcount;
//	m1.lock();
	{
		lock_guard<mutex> g(m1);
		cout << message << " is running..." << endl;
	}
//	m1.unlock();

	this_thread::sleep_for(chrono::seconds{ 4 });

//	m1.lock();
	{
		lock_guard<mutex> g(m1);
		cout << message << " is completed." << endl;
	}
//	m1.unlock();
	--tcount;
}



int main() {
////	int count = 0;
//	__asm {
//		mov eax, count
//		inc eax
//		mov count, eax
//	}

	thread t1{ display, "Thread #1" };
	thread t2{ display, "Thread #2" };
	thread t3{ display, "Thread #3" };
//	m1.lock();
	{
		lock_guard<mutex> g(m1);
		cout << "Thread #1 id = " << t1.get_id() << endl;
		cout << "Thread #2 id = " << t2.get_id() << endl;
		cout << "Thread #3 id = " << t3.get_id() << endl;
	}
//	m1.unlock();
	t1.join();
	t2.join();
	t3.join();

	cout << tcount << endl;
	return 0;
}