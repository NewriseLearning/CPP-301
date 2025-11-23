#pragma once

#include <memory>

template<typename T = int>
class CStack {
protected:
	T* m_values;
	int m_capacity;
	int m_count;
public:
	//CStack() : m_capacity(256), m_count(0) {
	//	m_values = new T[m_capacity];
	//}

	CStack(int capacity) : m_capacity(capacity), m_count(0) {
		m_values = new T[m_capacity];
	}

	CStack() : CStack(256) { }

	CStack(const CStack& obj) : 
		m_capacity(obj.m_capacity), m_count(obj.m_count) {
		size_t size = m_count * sizeof(T);
		m_values = new T[m_capacity];
		memcpy_s(m_values, size, obj.m_values, size);
	}

	~CStack() { delete m_values; }

	bool Empty() const { return m_count == 0; }
	int GetCount() const { return m_count; }

	void Resize(int capacity) {
		size_t old_size = m_capacity * sizeof(T);
		size_t new_size = capacity * sizeof(T);
		if (old_size > new_size) old_size = new_size;
		if (m_count > capacity) m_count = capacity;
		T* values = new T[capacity];
		memcpy_s(values, old_size, m_values, old_size);
		delete m_values; m_values = values;
		m_capacity = capacity;
	}

	void Trim() {
		Resize(m_count);
	}

	void Push(T value) {
		if (m_count == m_capacity) {
			int capacity = m_capacity * 2;
			if (capacity > 1000000) capacity = 100000;
			if (m_capacity == capacity) throw "Stack is full.";
			else Resize(capacity);
		}
		m_values[m_count++] = value;
	}

	T Pop() {
		if (m_count == 0) throw "Stack is empty.";
		return m_values[--m_count];
	}

};