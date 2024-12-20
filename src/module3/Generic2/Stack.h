#pragma once

#include <memory>

template<typename T = int, int SIZE = 256>
class CStack {
	T m_values[SIZE];
	int m_count;
public:
	CStack() : m_count(0) {
		memset(m_values, sizeof(m_values), 0);
	}
	bool Empty() const { return m_count == 0; }
	int GetCount() const { return m_count; }
	void Push(T value) {
		if (m_count == SIZE) throw "Stack  is full.";
		m_values[m_count++] = value;
	}
	T Pop() {
		if (m_count == 0) throw "Stack is empty.";
		return m_values[--m_count];
	}
};

typedef CStack<double> DoubleStack;
typedef CStack<int, 52> CardStack;
