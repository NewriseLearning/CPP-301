// Log.h : Declaration of the CLog

#pragma once
#include "resource.h"       // main symbols



#include "LogCom_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CLog

class ATL_NO_VTABLE CLog :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CLog, &CLSID_Log>,
	public IDispatchImpl<ILog, &IID_ILog, &LIBID_LogComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	BSTR m_source;
public:
	CLog();
	~CLog();

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CLog)
	COM_INTERFACE_ENTRY(ILog)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(get_Source)(BSTR* pVal);
	STDMETHOD(put_Source)(BSTR newVal);
	STDMETHOD(Write)(BSTR message);
};

OBJECT_ENTRY_AUTO(__uuidof(Log), CLog)
