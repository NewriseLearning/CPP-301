//	 nullable.h
#pragma once

#include <exception>

template<typename T>
class nullable {
	T m_value;
	bool m_hasValue;
public:
	nullable() : m_hasValue(false) { }
	nullable(void* ptr) : m_hasValue(false) {
		if (ptr != nullptr) throw std::exception("not null");
	}
	nullable(T value) : m_value(value), m_hasValue(true) { }
	bool hasValue() const { return m_hasValue; }
	operator T() {
		if (!m_hasValue) throw std::exception("null");
		return m_value;
	}
	bool operator == (void* ptr) {
		if (ptr == nullptr) return !m_hasValue;
		return false;
	}
};
