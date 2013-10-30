// dllmain.h : Declaration of module class.

class CResizableActiveXModule : public ATL::CAtlDllModuleT< CResizableActiveXModule >
{
public :
	DECLARE_LIBID(LIBID_ResizableActiveXLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_RESIZABLEACTIVEX, "{365B5AB4-02D7-4307-B677-18AB2F153D31}")
};

extern class CResizableActiveXModule _AtlModule;
