// ResizableTest.h : Declaration of the CResizableTest
#pragma once
#include "resource.h"       // main symbols
#include <atlctl.h>
#include "ResizableActiveX_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;



// CResizableTest
class ATL_NO_VTABLE CResizableTest :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CResizableTest, IResizableTest>,
	public IOleControlImpl<CResizableTest>,
	public IOleObjectImpl<CResizableTest>,
	public IOleInPlaceActiveObjectImpl<CResizableTest>,
	public IViewObjectExImpl<CResizableTest>,
	public IOleInPlaceObjectWindowlessImpl<CResizableTest>,
	public ISupportErrorInfo,
	public IObjectWithSiteImpl<CResizableTest>,
	public IQuickActivateImpl<CResizableTest>,
#ifndef _WIN32_WCE
	public IDataObjectImpl<CResizableTest>,
#endif
	public IProvideClassInfo2Impl<&CLSID_ResizableTest, NULL, &LIBID_ResizableActiveXLib>,
	public IObjectSafetyImpl<CResizableTest, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
	public CComCoClass<CResizableTest, &CLSID_ResizableTest>,
	public CComCompositeControl<CResizableTest>,
	public CDialogResize<CResizableTest>
{
public:


	CResizableTest()
	{
		m_bWindowOnly = TRUE;
		CalcExtent(m_sizeExtent);
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_INSIDEOUT |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST
)

DECLARE_REGISTRY_RESOURCEID(IDR_RESIZABLETEST)


BEGIN_COM_MAP(CResizableTest)
	COM_INTERFACE_ENTRY(IResizableTest)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IQuickActivate)
#ifndef _WIN32_WCE
	COM_INTERFACE_ENTRY(IDataObject)
#endif
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY_IID(IID_IObjectSafety, IObjectSafety)
END_COM_MAP()

BEGIN_PROP_MAP(CResizableTest)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY_TYPE("AutoSize", DISPID_AUTOSIZE, CLSID_NULL, VT_BOOL)
	PROP_ENTRY_TYPE("TabStop", DISPID_TABSTOP, CLSID_NULL, VT_BOOL)
	// Example entries
	// PROP_ENTRY_TYPE("Property Name", dispid, clsid, vtType)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()


BEGIN_MSG_MAP(CResizableTest)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	CHAIN_MSG_MAP(CComCompositeControl<CResizableTest>)
	COMMAND_HANDLER(IDC_BTN_SELECTFOLDER, BN_CLICKED, OnBnClickedBtnSelectfolder)
	CHAIN_MSG_MAP(CDialogResize<CResizableTest>)
END_MSG_MAP()

BEGIN_DLGRESIZE_MAP(CResizableTest)
	DLGRESIZE_CONTROL(IDC_BTN_SELECTFOLDER, DLSZ_MOVE_X)
	DLGRESIZE_CONTROL(IDC_EDIT_PATH, DLSZ_SIZE_X)
	DLGRESIZE_CONTROL(IDC_LIST_FILE, DLSZ_SIZE_X | DLSZ_SIZE_Y)
END_DLGRESIZE_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

BEGIN_SINK_MAP(CResizableTest)
	//Make sure the Event Handlers have __stdcall calling convention
END_SINK_MAP()

	STDMETHOD(OnAmbientPropertyChange)(DISPID dispid)
	{
		if (dispid == DISPID_AMBIENT_BACKCOLOR)
		{
			SetBackgroundColorFromAmbient();
			FireViewChange();
		}
		return IOleControlImpl<CResizableTest>::OnAmbientPropertyChange(dispid);
	}
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* const arr[] =
		{
			&IID_IResizableTest,
		};

		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IResizableTest
	void OnAutoSizeChanged()
	{
		ATLTRACE(_T("OnAutoSizeChanged\n"));
	}
	BOOL m_bTabStop;
	void OnTabStopChanged()
	{
		ATLTRACE(_T("OnTabStopChanged\n"));
	}

	enum { IDD = IDD_RESIZABLETEST };

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}
	LRESULT OnBnClickedBtnSelectfolder(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	LRESULT OnInitDialog(
		_In_ UINT /*uMsg*/, 
		_In_ WPARAM /*wParam*/, 
		_In_ LPARAM /*lParam*/, 
		_Out_  BOOL& bHandled)
	{
		DlgResize_Init(false, false, WS_CHILD);
		bHandled = FALSE;
		return 1;
	}
};

OBJECT_ENTRY_AUTO(__uuidof(ResizableTest), CResizableTest)
