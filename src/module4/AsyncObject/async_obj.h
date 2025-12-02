//	async_obj.h
#pragma once

#include <thread>

template<typename T>
class async_object {
protected:
	std::thread m_thread;
private:
	static void callback(async_object* obj, T state) {
	//	delay for the constructor to completed so that
	//	you have access to the correct vtable because
	//	you cannot call run on async_object in vtable
	//	because it's pure virtual
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		obj->run(state);	
	}
public:
	virtual void run(T state) = 0;
	async_object(T state) : m_thread(callback, this, state) {}
	void wait() { m_thread.join(); }
};
