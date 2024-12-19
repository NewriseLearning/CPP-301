// dllmain.h : Declaration of module class.

class CLogComModule : public ATL::CAtlDllModuleT< CLogComModule >
{
public :
	DECLARE_LIBID(LIBID_LogComLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_LOGCOM, "{bc75ec4e-9238-4803-bcda-d8800c7deaf3}")
};

extern class CLogComModule _AtlModule;
