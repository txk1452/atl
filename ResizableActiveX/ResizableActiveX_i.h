

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Oct 30 00:18:47 2013
 */
/* Compiler settings for ResizableActiveX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ResizableActiveX_i_h__
#define __ResizableActiveX_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IResizableTest_FWD_DEFINED__
#define __IResizableTest_FWD_DEFINED__
typedef interface IResizableTest IResizableTest;
#endif 	/* __IResizableTest_FWD_DEFINED__ */


#ifndef __ResizableTest_FWD_DEFINED__
#define __ResizableTest_FWD_DEFINED__

#ifdef __cplusplus
typedef class ResizableTest ResizableTest;
#else
typedef struct ResizableTest ResizableTest;
#endif /* __cplusplus */

#endif 	/* __ResizableTest_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IResizableTest_INTERFACE_DEFINED__
#define __IResizableTest_INTERFACE_DEFINED__

/* interface IResizableTest */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IResizableTest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("911924F2-02BB-4776-9164-51619209FCFB")
    IResizableTest : public IDispatch
    {
    public:
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_AutoSize( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_AutoSize( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_TabStop( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_TabStop( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IResizableTestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IResizableTest * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IResizableTest * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IResizableTest * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IResizableTest * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IResizableTest * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IResizableTest * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IResizableTest * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSize )( 
            IResizableTest * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSize )( 
            IResizableTest * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabStop )( 
            IResizableTest * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabStop )( 
            IResizableTest * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        END_INTERFACE
    } IResizableTestVtbl;

    interface IResizableTest
    {
        CONST_VTBL struct IResizableTestVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IResizableTest_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IResizableTest_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IResizableTest_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IResizableTest_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IResizableTest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IResizableTest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IResizableTest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IResizableTest_put_AutoSize(This,vbool)	\
    ( (This)->lpVtbl -> put_AutoSize(This,vbool) ) 

#define IResizableTest_get_AutoSize(This,pbool)	\
    ( (This)->lpVtbl -> get_AutoSize(This,pbool) ) 

#define IResizableTest_put_TabStop(This,vbool)	\
    ( (This)->lpVtbl -> put_TabStop(This,vbool) ) 

#define IResizableTest_get_TabStop(This,pbool)	\
    ( (This)->lpVtbl -> get_TabStop(This,pbool) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IResizableTest_INTERFACE_DEFINED__ */



#ifndef __ResizableActiveXLib_LIBRARY_DEFINED__
#define __ResizableActiveXLib_LIBRARY_DEFINED__

/* library ResizableActiveXLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ResizableActiveXLib;

EXTERN_C const CLSID CLSID_ResizableTest;

#ifdef __cplusplus

class DECLSPEC_UUID("1EEE1EA2-BCEA-4383-ADBC-EF7D99CE8751")
ResizableTest;
#endif
#endif /* __ResizableActiveXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


