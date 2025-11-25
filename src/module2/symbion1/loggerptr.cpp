#include "symbion.h"
#include <exception>

namespace symbion {

	CLoggerPtr::CLoggerPtr() : m_ptr(nullptr) {
	}

	CLoggerPtr::CLoggerPtr(CBaseLogger* ptr) : m_ptr(nullptr) {
		PutPtr(ptr);
	}

	CLoggerPtr::CLoggerPtr(const CLoggerPtr& obj) {
		throw new std::exception("Attempt to unique pointer");
	}

	CLoggerPtr::~CLoggerPtr() {
		if (m_ptr) delete m_ptr;
	}

	void CLoggerPtr::PutPtr(CBaseLogger* ptr) {
		if (m_ptr != ptr) {
			if (m_ptr) delete m_ptr;
			m_ptr = ptr;
		}
	}

	CBaseLogger* CLoggerPtr::GetPtr() const {
		return m_ptr;
	}

	CLoggerPtr::operator CBaseLogger* () const {
		return GetPtr();
	}

	CLoggerPtr& CLoggerPtr::operator = (CBaseLogger* ptr) {
		PutPtr(ptr); return *this;
	}

	CBaseLogger* CLoggerPtr::operator ->() const {
		return GetPtr();
	}

}
