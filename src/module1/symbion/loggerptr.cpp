#include "symbion.h"
#include <exception>

namespace symbion {
	CLoggerPtr::CLoggerPtr() : m_ptr(nullptr) {

	}
	CLoggerPtr::CLoggerPtr(CBaseLogger* ptr) : CLoggerPtr() {
		PutPtr(ptr);
	}
	CLoggerPtr::CLoggerPtr(const CLoggerPtr& obj) {
		throw std::exception("Attempt to copy unique ptr");
	}
	CLoggerPtr::~CLoggerPtr() {
		if (m_ptr != nullptr) delete m_ptr;
	}

	void CLoggerPtr::PutPtr(CBaseLogger* ptr) {
		if (ptr != m_ptr && m_ptr != nullptr) delete m_ptr;
		m_ptr = ptr;
	}

	CBaseLogger* CLoggerPtr::GetPtr() const {
		return m_ptr;
	}

	CLoggerPtr& CLoggerPtr::operator =(CBaseLogger* ptr) {
		PutPtr(ptr); return *this;	// return current object by reference
	}

	CLoggerPtr::operator CBaseLogger* () const {
		return GetPtr(); // return m_ptr;
	}

	CBaseLogger* CLoggerPtr::operator ->() const {
		return GetPtr(); // return m_ptr;
	}
}
