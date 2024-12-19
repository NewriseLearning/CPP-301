

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for LogCom.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0626 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __LogCom_i_h__
#define __LogCom_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __ILog_FWD_DEFINED__
#define __ILog_FWD_DEFINED__
typedef interface ILog ILog;

#endif 	/* __ILog_FWD_DEFINED__ */


#ifndef __Log_FWD_DEFINED__
#define __Log_FWD_DEFINED__

#ifdef __cplusplus
typedef class Log Log;
#else
typedef struct Log Log;
#endif /* __cplusplus */

#endif 	/* __Log_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ILog_INTERFACE_DEFINED__
#define __ILog_INTERFACE_DEFINED__

/* interface ILog */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ILog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("357eae98-179c-4927-8a6f-b3f8e898df47")
    ILog : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Source( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Source( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ BSTR message) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ILogVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILog * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILog * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILog * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILog * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILog * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILog * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILog * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ILog, get_Source)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Source )( 
            ILog * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(ILog, put_Source)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Source )( 
            ILog * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(ILog, Write)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ILog * This,
            /* [in] */ BSTR message);
        
        END_INTERFACE
    } ILogVtbl;

    interface ILog
    {
        CONST_VTBL struct ILogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILog_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILog_get_Source(This,pVal)	\
    ( (This)->lpVtbl -> get_Source(This,pVal) ) 

#define ILog_put_Source(This,newVal)	\
    ( (This)->lpVtbl -> put_Source(This,newVal) ) 

#define ILog_Write(This,message)	\
    ( (This)->lpVtbl -> Write(This,message) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILog_INTERFACE_DEFINED__ */



#ifndef __LogComLib_LIBRARY_DEFINED__
#define __LogComLib_LIBRARY_DEFINED__

/* library LogComLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_LogComLib;

EXTERN_C const CLSID CLSID_Log;

#ifdef __cplusplus

class DECLSPEC_UUID("f5c44c50-d02a-432a-a8b9-3b237cfbda70")
Log;
#endif
#endif /* __LogComLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


