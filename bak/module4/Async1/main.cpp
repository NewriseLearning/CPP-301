#include <thread>

template<typename T>
class async_object {
protected:
	std::thread * m_thread;
	T m_state;
private:
	static void callback(async_object* obj) {
//		wait a while for the VTBL * to be assigned in the object by another thread
//		std::this_thread::sleep_for(std::chrono::milliseconds(200));
//		calling function through VTBL * assign to the object
		obj->run(obj->m_state);
	}
public:
	void invoke() {
		if (!m_thread) m_thread = new std::thread(callback, this);
	}
	virtual void run(T state) = 0;
	async_object(T state) : m_thread(nullptr), m_state(state) { }
	void wait() { if (m_thread) m_thread->join(); }
	~async_object() {
		if (m_thread) delete m_thread;
	}
};

#include <Windows.h>
#include <tchar.h>

class async_msgbox : public async_object<LPCTSTR> {
public:
	async_msgbox(LPCTSTR message) : async_object(message) { }
	void run(LPCTSTR message) {
		MessageBox(NULL, message, _T("Message"), MB_OK);
	}
};

int main() {
	async_msgbox b1(_T("Hello!"));
	async_msgbox b2(_T("Goodbye!"));
	async_msgbox b3(_T("Sayonara!"));
	async_msgbox b4(_T("Ciao!"));
	b1.invoke();	// ask the object to run on its own thread
	b2.invoke();	// ask the object to run on its own thread
	b3.invoke();	// ask the object to run on its own thread
	b4.invoke();	// ask the object to run on its own thread
	b1.wait();
	b2.wait();
	b3.wait();
	b4.wait();
	return 0;
}
