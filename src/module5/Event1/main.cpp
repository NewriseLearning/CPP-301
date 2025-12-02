
#include <cstdio>
#include <set>
#include <functional>
using namespace std::placeholders;

template<typename T>
class EventListener {
public:
	virtual void Notify(T event) = 0;
	friend bool operator < (EventListener<T>& obj1, EventListener<T>& obj2) {
		return true; // function order is not important
	}
};


template<typename T>
class FuncComparer {
public:
	bool operator()(
		const std::function<void(T)>& obj1,
		const std::function<void(T)>& obj2) const {
		return true; // function order is not important
	}
};

//template<typename T>
//class Event {
//private:
//	std::set<EventListener<T>*> m_listeners;
//public:
//	void Add(EventListener<T>& listener) { m_listeners.insert(&listener); }
//	void Remove(EventListener<T>& listener) { m_listeners.erase(&listener); }
//	void Invoke(T value) {
//		for (auto listener : m_listeners)
//			listener->Notify(value);
//	}
//};

template<typename T>
class Event {
private:
	std::set<std::function<void(T)>, FuncComparer<T>> m_listeners;
public:
	void Add(std::function<void(T)> listener) { m_listeners.insert(listener); }
	void Remove(std::function<void(T)> listener) {
		m_listeners.erase(listener);
	}
	void Invoke(T value) {
		for (auto listener : m_listeners)
			listener(value);
	}
};

//class EventSubscriber :
//	public EventListener<const char*>,
//	public EventListener<int> {
//public:
//	void Notify(const char* event) {
//		printf("%s event received.\n", event);
//	}
//	void Notify(int event) {
//		printf("int (%d) event received.\n", event);
//	}
//};

class EventSubscriber :
	public EventListener<const char*>,
	public EventListener<int> {
public:
	void Notify(const char* event) {
		printf("%s event received.\n", event);
	}
	void Notify(int event) {
		printf("int (%d) event received.\n", event);
	}
	void Notify1(const char* event) { Notify(event); }
	void Notify2(int event) { Notify(event); }
};

int main() {
	Event<const char*> e1;
	Event<int> e2;

	//EventSubscriber s1;
	//EventSubscriber s2;
	//e1.Add(s1);
	//e2.Add(s1);
	//e1.Add(s2);
	//e2.Add(s2);


	std::function<void(const char*)> f1 = [](const char* event) {
		printf("%s event received.\n", event);
	};
	std::function<void(int)> f2 = [](int event) {
		printf("int (%d) event received.\n", event);
	};
	e1.Add(f1);
	e2.Add(f2);

	//	e1.Invoke("Hello!");
	//	e2.Invoke(123);



	EventSubscriber s1;
	//auto f3 = std::bind(&EventSubscriber::Notify1, s1, "Goodbye!");
	//auto f4 = std::bind(&EventSubscriber::Notify2, s1, 999);
	//f3();
	//f4();


	auto f3 = std::bind(&EventSubscriber::Notify1, s1, _1);
	auto f4 = std::bind(&EventSubscriber::Notify2, s1, _1);
	f3("Goodbye!");
	f4(999);

}