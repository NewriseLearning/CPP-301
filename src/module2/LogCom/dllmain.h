// dllmain.h : Declaration of module class.

class CLogComModule : public ATL::CAtlDllModuleT< CLogComModule >
{
public :
	DECLARE_LIBID(LIBID_LogComLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_LOGCOM, "{6bc23693-d1d1-4d56-b16a-ef03cd3d841d}")
	STDMETHOD(get_Source)(BSTR* pVal);
	STDMETHOD(put_Source)(BSTR newVal);
	STDMETHOD(Write)(BSTR message);
};

extern class CLogComModule _AtlModule;
