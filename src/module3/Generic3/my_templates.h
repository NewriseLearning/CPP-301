//	my_templates.h
#pragma once

#include <iostream>
#include <memory.h>

template <typename T>
class CStack {
protected:
	T* m_values;
	int m_capacity;
	int m_count;

public:
	CStack(int capacity) : m_capacity(capacity), m_count(0) {
		m_values = new T[m_capacity];
	}
	CStack() : CStack(256) { }
	CStack(CStack& obj) :
		m_capacity(obj.m_capacity),
		m_count(obj.m_count) {
		size_t size1 = m_capacity * sizeof(T);
		size_t size2 = m_count * sizeof(T);
		m_values = new T[m_capacity];
		memcpy_s(m_values, size1, obj.m_values, size2);
	}
	~CStack() { delete m_values; }

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

	bool Empty() const { return m_count == 0; }
	int GetCount() const { return m_count; }
	void Push(T value) {
		if (m_count == m_capacity) {
			int capacity = m_capacity * 2;
			if (capacity > 1000000) capacity = 1000000;
			if (m_capacity == capacity) throw "Stack is full.";
			else Resize(capacity);
		}
		m_values[m_count++] = value;
	}
	T Pop() {
		if (m_count == 0) throw "Stack is empty.";
		return m_values[--m_count];
	}
	void Trim() {
		Resize(m_count);
	}
};


template<typename T>
class nullable {
private:
	T m_value;
	bool m_hasValue;
public:
	nullable() : m_value(), m_hasValue(false) { }
	nullable(void* ptr) : nullable() { if (ptr) throw std::exception("not null"); }
	nullable(T value) : m_value(value), m_hasValue(true) { }
	bool hasValue() const { return m_hasValue; }
	//T getValue() { 
	//	if (!m_hasValue) throw std::exception("null");
	//	return m_value;
	//}
	//operator T() { return getValue(); }
	operator T() {
		if (!m_hasValue) throw std::exception("null");
		return m_value;
	}
	// void setValue(T value) { m_value = value; m_hasValue = true; }
	nullable<T>& operator = (T value) {
		m_value = value;
		m_hasValue = true;
		return *this;
	}
	nullable<T>& operator = (void* ptr) {
		if (ptr) throw std::exception("not null");
		m_hasValue = false;
		return *this;
	}
	bool operator == (void* ptr) {
		if (ptr) throw std::exception("not null");
		return !m_hasValue;
	}
};
