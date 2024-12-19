// dllmain.h : Declaration of module class.

class CLogComModule : public ATL::CAtlDllModuleT< CLogComModule >
{
public :
	DECLARE_LIBID(LIBID_LogComLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_LOGCOM, "{bc75ec4e-9238-4803-bcda-d8800c7deaf3}")
	STDMETHOD(get_Source)(BSTR* pVal);
	STDMETHOD(put_Source)(BSTR newVal);
	STDMETHOD(Write)(BSTR message);
};

extern class CLogComModule _AtlModule;
