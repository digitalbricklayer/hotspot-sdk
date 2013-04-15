

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Fri Dec 01 11:16:37 2006
 */
/* Compiler settings for .\SensatronicsSDK.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
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

#ifndef __SensatronicsSDK_h__
#define __SensatronicsSDK_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDataConnector_FWD_DEFINED__
#define __IDataConnector_FWD_DEFINED__
typedef interface IDataConnector IDataConnector;
#endif 	/* __IDataConnector_FWD_DEFINED__ */


#ifndef __IDataPoint_FWD_DEFINED__
#define __IDataPoint_FWD_DEFINED__
typedef interface IDataPoint IDataPoint;
#endif 	/* __IDataPoint_FWD_DEFINED__ */


#ifndef __IProbe_FWD_DEFINED__
#define __IProbe_FWD_DEFINED__
typedef interface IProbe IProbe;
#endif 	/* __IProbe_FWD_DEFINED__ */


#ifndef __IProbeCollection_FWD_DEFINED__
#define __IProbeCollection_FWD_DEFINED__
typedef interface IProbeCollection IProbeCollection;
#endif 	/* __IProbeCollection_FWD_DEFINED__ */


#ifndef __ISensatronicsDevice_FWD_DEFINED__
#define __ISensatronicsDevice_FWD_DEFINED__
typedef interface ISensatronicsDevice ISensatronicsDevice;
#endif 	/* __ISensatronicsDevice_FWD_DEFINED__ */


#ifndef __ISensatronicsModelE_FWD_DEFINED__
#define __ISensatronicsModelE_FWD_DEFINED__
typedef interface ISensatronicsModelE ISensatronicsModelE;
#endif 	/* __ISensatronicsModelE_FWD_DEFINED__ */


#ifndef __ISensatronicsModelF_FWD_DEFINED__
#define __ISensatronicsModelF_FWD_DEFINED__
typedef interface ISensatronicsModelF ISensatronicsModelF;
#endif 	/* __ISensatronicsModelF_FWD_DEFINED__ */


#ifndef ___IDataConnectorEvents_FWD_DEFINED__
#define ___IDataConnectorEvents_FWD_DEFINED__
typedef interface _IDataConnectorEvents _IDataConnectorEvents;
#endif 	/* ___IDataConnectorEvents_FWD_DEFINED__ */


#ifndef __DataConnector_FWD_DEFINED__
#define __DataConnector_FWD_DEFINED__

#ifdef __cplusplus
typedef class DataConnector DataConnector;
#else
typedef struct DataConnector DataConnector;
#endif /* __cplusplus */

#endif 	/* __DataConnector_FWD_DEFINED__ */


#ifndef ___IDataPointEvents_FWD_DEFINED__
#define ___IDataPointEvents_FWD_DEFINED__
typedef interface _IDataPointEvents _IDataPointEvents;
#endif 	/* ___IDataPointEvents_FWD_DEFINED__ */


#ifndef __DataPoint_FWD_DEFINED__
#define __DataPoint_FWD_DEFINED__

#ifdef __cplusplus
typedef class DataPoint DataPoint;
#else
typedef struct DataPoint DataPoint;
#endif /* __cplusplus */

#endif 	/* __DataPoint_FWD_DEFINED__ */


#ifndef ___IProbeEvents_FWD_DEFINED__
#define ___IProbeEvents_FWD_DEFINED__
typedef interface _IProbeEvents _IProbeEvents;
#endif 	/* ___IProbeEvents_FWD_DEFINED__ */


#ifndef __Probe_FWD_DEFINED__
#define __Probe_FWD_DEFINED__

#ifdef __cplusplus
typedef class Probe Probe;
#else
typedef struct Probe Probe;
#endif /* __cplusplus */

#endif 	/* __Probe_FWD_DEFINED__ */


#ifndef __ProbeCollection_FWD_DEFINED__
#define __ProbeCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class ProbeCollection ProbeCollection;
#else
typedef struct ProbeCollection ProbeCollection;
#endif /* __cplusplus */

#endif 	/* __ProbeCollection_FWD_DEFINED__ */


#ifndef ___ISensatronicsModelEEvents_FWD_DEFINED__
#define ___ISensatronicsModelEEvents_FWD_DEFINED__
typedef interface _ISensatronicsModelEEvents _ISensatronicsModelEEvents;
#endif 	/* ___ISensatronicsModelEEvents_FWD_DEFINED__ */


#ifndef __SensatronicsModelE_FWD_DEFINED__
#define __SensatronicsModelE_FWD_DEFINED__

#ifdef __cplusplus
typedef class SensatronicsModelE SensatronicsModelE;
#else
typedef struct SensatronicsModelE SensatronicsModelE;
#endif /* __cplusplus */

#endif 	/* __SensatronicsModelE_FWD_DEFINED__ */


#ifndef ___ISensatronicsModelFEvents_FWD_DEFINED__
#define ___ISensatronicsModelFEvents_FWD_DEFINED__
typedef interface _ISensatronicsModelFEvents _ISensatronicsModelFEvents;
#endif 	/* ___ISensatronicsModelFEvents_FWD_DEFINED__ */


#ifndef __SensatronicsModelF_FWD_DEFINED__
#define __SensatronicsModelF_FWD_DEFINED__

#ifdef __cplusplus
typedef class SensatronicsModelF SensatronicsModelF;
#else
typedef struct SensatronicsModelF SensatronicsModelF;
#endif /* __cplusplus */

#endif 	/* __SensatronicsModelF_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IDataConnector_INTERFACE_DEFINED__
#define __IDataConnector_INTERFACE_DEFINED__

/* interface IDataConnector */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDataConnector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ACD672B0-42DE-4309-B7EE-60F22A2223B4")
    IDataConnector : public IDispatch
    {
    public:
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE RequestModelEXMLData( 
            /* [in] */ BSTR Id,
            /* [in] */ BSTR Val,
            /* [retval][out] */ LONG *Handler) = 0;
        
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE RequestModelFSerialComConfigData( 
            /* [in] */ BSTR Id,
            /* [in] */ BSTR ComPort,
            /* [retval][out] */ LONG *Handler) = 0;
        
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE RequestModelFSerialComData( 
            /* [in] */ BSTR Id,
            /* [in] */ BSTR ComPort,
            /* [retval][out] */ LONG *Handler) = 0;
        
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE RequestModelEXMLConfigData( 
            /* [in] */ BSTR Id,
            /* [in] */ BSTR Val,
            /* [retval][out] */ LONG *Handler) = 0;
        
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE RequestModelEHTTPConfigAndData( 
            /* [in] */ BSTR Id,
            /* [in] */ BSTR IpAddress,
            /* [in] */ BSTR ConfigPath,
            /* [in] */ BSTR DataPath,
            /* [in] */ BSTR Model,
            /* [out] */ LONG *ConfigHandler,
            /* [out] */ LONG *DataHandler) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDataConnectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDataConnector * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDataConnector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDataConnector * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDataConnector * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDataConnector * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDataConnector * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDataConnector * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RequestModelEXMLData )( 
            IDataConnector * This,
            /* [in] */ BSTR Id,
            /* [in] */ BSTR Val,
            /* [retval][out] */ LONG *Handler);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RequestModelFSerialComConfigData )( 
            IDataConnector * This,
            /* [in] */ BSTR Id,
            /* [in] */ BSTR ComPort,
            /* [retval][out] */ LONG *Handler);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RequestModelFSerialComData )( 
            IDataConnector * This,
            /* [in] */ BSTR Id,
            /* [in] */ BSTR ComPort,
            /* [retval][out] */ LONG *Handler);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RequestModelEXMLConfigData )( 
            IDataConnector * This,
            /* [in] */ BSTR Id,
            /* [in] */ BSTR Val,
            /* [retval][out] */ LONG *Handler);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RequestModelEHTTPConfigAndData )( 
            IDataConnector * This,
            /* [in] */ BSTR Id,
            /* [in] */ BSTR IpAddress,
            /* [in] */ BSTR ConfigPath,
            /* [in] */ BSTR DataPath,
            /* [in] */ BSTR Model,
            /* [out] */ LONG *ConfigHandler,
            /* [out] */ LONG *DataHandler);
        
        END_INTERFACE
    } IDataConnectorVtbl;

    interface IDataConnector
    {
        CONST_VTBL struct IDataConnectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataConnector_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDataConnector_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDataConnector_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDataConnector_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDataConnector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDataConnector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDataConnector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDataConnector_RequestModelEXMLData(This,Id,Val,Handler)	\
    (This)->lpVtbl -> RequestModelEXMLData(This,Id,Val,Handler)

#define IDataConnector_RequestModelFSerialComConfigData(This,Id,ComPort,Handler)	\
    (This)->lpVtbl -> RequestModelFSerialComConfigData(This,Id,ComPort,Handler)

#define IDataConnector_RequestModelFSerialComData(This,Id,ComPort,Handler)	\
    (This)->lpVtbl -> RequestModelFSerialComData(This,Id,ComPort,Handler)

#define IDataConnector_RequestModelEXMLConfigData(This,Id,Val,Handler)	\
    (This)->lpVtbl -> RequestModelEXMLConfigData(This,Id,Val,Handler)

#define IDataConnector_RequestModelEHTTPConfigAndData(This,Id,IpAddress,ConfigPath,DataPath,Model,ConfigHandler,DataHandler)	\
    (This)->lpVtbl -> RequestModelEHTTPConfigAndData(This,Id,IpAddress,ConfigPath,DataPath,Model,ConfigHandler,DataHandler)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE IDataConnector_RequestModelEXMLData_Proxy( 
    IDataConnector * This,
    /* [in] */ BSTR Id,
    /* [in] */ BSTR Val,
    /* [retval][out] */ LONG *Handler);


void __RPC_STUB IDataConnector_RequestModelEXMLData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE IDataConnector_RequestModelFSerialComConfigData_Proxy( 
    IDataConnector * This,
    /* [in] */ BSTR Id,
    /* [in] */ BSTR ComPort,
    /* [retval][out] */ LONG *Handler);


void __RPC_STUB IDataConnector_RequestModelFSerialComConfigData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE IDataConnector_RequestModelFSerialComData_Proxy( 
    IDataConnector * This,
    /* [in] */ BSTR Id,
    /* [in] */ BSTR ComPort,
    /* [retval][out] */ LONG *Handler);


void __RPC_STUB IDataConnector_RequestModelFSerialComData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE IDataConnector_RequestModelEXMLConfigData_Proxy( 
    IDataConnector * This,
    /* [in] */ BSTR Id,
    /* [in] */ BSTR Val,
    /* [retval][out] */ LONG *Handler);


void __RPC_STUB IDataConnector_RequestModelEXMLConfigData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE IDataConnector_RequestModelEHTTPConfigAndData_Proxy( 
    IDataConnector * This,
    /* [in] */ BSTR Id,
    /* [in] */ BSTR IpAddress,
    /* [in] */ BSTR ConfigPath,
    /* [in] */ BSTR DataPath,
    /* [in] */ BSTR Model,
    /* [out] */ LONG *ConfigHandler,
    /* [out] */ LONG *DataHandler);


void __RPC_STUB IDataConnector_RequestModelEHTTPConfigAndData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDataConnector_INTERFACE_DEFINED__ */


#ifndef __IDataPoint_INTERFACE_DEFINED__
#define __IDataPoint_INTERFACE_DEFINED__

/* interface IDataPoint */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDataPoint;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1F23ADF3-2EB3-47FC-B6C5-023D6E982C9B")
    IDataPoint : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Unit( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Unit( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Time( 
            /* [retval][out] */ DATE *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Time( 
            /* [in] */ DATE newVal) = 0;
        
        virtual /* [hidden][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UTCTime( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UTCTime( 
            /* [in] */ LONGLONG newVal) = 0;
        
        virtual /* [hidden][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UTCTimeAsString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UTCTimeAsString( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDataPointVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDataPoint * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDataPoint * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDataPoint * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDataPoint * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDataPoint * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDataPoint * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDataPoint * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IDataPoint * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IDataPoint * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Unit )( 
            IDataPoint * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Unit )( 
            IDataPoint * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Time )( 
            IDataPoint * This,
            /* [retval][out] */ DATE *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Time )( 
            IDataPoint * This,
            /* [in] */ DATE newVal);
        
        /* [hidden][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UTCTime )( 
            IDataPoint * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UTCTime )( 
            IDataPoint * This,
            /* [in] */ LONGLONG newVal);
        
        /* [hidden][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UTCTimeAsString )( 
            IDataPoint * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UTCTimeAsString )( 
            IDataPoint * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IDataPointVtbl;

    interface IDataPoint
    {
        CONST_VTBL struct IDataPointVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataPoint_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDataPoint_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDataPoint_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDataPoint_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDataPoint_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDataPoint_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDataPoint_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDataPoint_get_Value(This,pVal)	\
    (This)->lpVtbl -> get_Value(This,pVal)

#define IDataPoint_put_Value(This,newVal)	\
    (This)->lpVtbl -> put_Value(This,newVal)

#define IDataPoint_get_Unit(This,pVal)	\
    (This)->lpVtbl -> get_Unit(This,pVal)

#define IDataPoint_put_Unit(This,newVal)	\
    (This)->lpVtbl -> put_Unit(This,newVal)

#define IDataPoint_get_Time(This,pVal)	\
    (This)->lpVtbl -> get_Time(This,pVal)

#define IDataPoint_put_Time(This,newVal)	\
    (This)->lpVtbl -> put_Time(This,newVal)

#define IDataPoint_get_UTCTime(This,pVal)	\
    (This)->lpVtbl -> get_UTCTime(This,pVal)

#define IDataPoint_put_UTCTime(This,newVal)	\
    (This)->lpVtbl -> put_UTCTime(This,newVal)

#define IDataPoint_get_UTCTimeAsString(This,pVal)	\
    (This)->lpVtbl -> get_UTCTimeAsString(This,pVal)

#define IDataPoint_put_UTCTimeAsString(This,newVal)	\
    (This)->lpVtbl -> put_UTCTimeAsString(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDataPoint_get_Value_Proxy( 
    IDataPoint * This,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB IDataPoint_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDataPoint_put_Value_Proxy( 
    IDataPoint * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IDataPoint_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDataPoint_get_Unit_Proxy( 
    IDataPoint * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IDataPoint_get_Unit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDataPoint_put_Unit_Proxy( 
    IDataPoint * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IDataPoint_put_Unit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDataPoint_get_Time_Proxy( 
    IDataPoint * This,
    /* [retval][out] */ DATE *pVal);


void __RPC_STUB IDataPoint_get_Time_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDataPoint_put_Time_Proxy( 
    IDataPoint * This,
    /* [in] */ DATE newVal);


void __RPC_STUB IDataPoint_put_Time_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDataPoint_get_UTCTime_Proxy( 
    IDataPoint * This,
    /* [retval][out] */ LONGLONG *pVal);


void __RPC_STUB IDataPoint_get_UTCTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDataPoint_put_UTCTime_Proxy( 
    IDataPoint * This,
    /* [in] */ LONGLONG newVal);


void __RPC_STUB IDataPoint_put_UTCTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDataPoint_get_UTCTimeAsString_Proxy( 
    IDataPoint * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IDataPoint_get_UTCTimeAsString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDataPoint_put_UTCTimeAsString_Proxy( 
    IDataPoint * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IDataPoint_put_UTCTimeAsString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDataPoint_INTERFACE_DEFINED__ */


#ifndef __IProbe_INTERFACE_DEFINED__
#define __IProbe_INTERFACE_DEFINED__

/* interface IProbe */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IProbe;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DE068255-D6A3-4F6A-A19A-8626CC1E23FB")
    IProbe : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Type( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Number( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Number( 
            /* [in] */ SHORT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Group( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Group( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MostRecentDataPoint( 
            /* [retval][out] */ IDataPoint **pVal) = 0;
        
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE Poll( 
            /* [in] */ IDataPoint *pDataPoint) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IProbeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProbe * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProbe * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProbe * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IProbe * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IProbe * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IProbe * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IProbe * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IProbe * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IProbe * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IProbe * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Type )( 
            IProbe * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Number )( 
            IProbe * This,
            /* [retval][out] */ SHORT *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Number )( 
            IProbe * This,
            /* [in] */ SHORT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Group )( 
            IProbe * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Group )( 
            IProbe * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MostRecentDataPoint )( 
            IProbe * This,
            /* [retval][out] */ IDataPoint **pVal);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Poll )( 
            IProbe * This,
            /* [in] */ IDataPoint *pDataPoint);
        
        END_INTERFACE
    } IProbeVtbl;

    interface IProbe
    {
        CONST_VTBL struct IProbeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProbe_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IProbe_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IProbe_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IProbe_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IProbe_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IProbe_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IProbe_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IProbe_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define IProbe_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define IProbe_get_Type(This,pVal)	\
    (This)->lpVtbl -> get_Type(This,pVal)

#define IProbe_put_Type(This,newVal)	\
    (This)->lpVtbl -> put_Type(This,newVal)

#define IProbe_get_Number(This,pVal)	\
    (This)->lpVtbl -> get_Number(This,pVal)

#define IProbe_put_Number(This,newVal)	\
    (This)->lpVtbl -> put_Number(This,newVal)

#define IProbe_get_Group(This,pVal)	\
    (This)->lpVtbl -> get_Group(This,pVal)

#define IProbe_put_Group(This,newVal)	\
    (This)->lpVtbl -> put_Group(This,newVal)

#define IProbe_get_MostRecentDataPoint(This,pVal)	\
    (This)->lpVtbl -> get_MostRecentDataPoint(This,pVal)

#define IProbe_Poll(This,pDataPoint)	\
    (This)->lpVtbl -> Poll(This,pDataPoint)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IProbe_get_Name_Proxy( 
    IProbe * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IProbe_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IProbe_put_Name_Proxy( 
    IProbe * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IProbe_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IProbe_get_Type_Proxy( 
    IProbe * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IProbe_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IProbe_put_Type_Proxy( 
    IProbe * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IProbe_put_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IProbe_get_Number_Proxy( 
    IProbe * This,
    /* [retval][out] */ SHORT *pVal);


void __RPC_STUB IProbe_get_Number_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IProbe_put_Number_Proxy( 
    IProbe * This,
    /* [in] */ SHORT newVal);


void __RPC_STUB IProbe_put_Number_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IProbe_get_Group_Proxy( 
    IProbe * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IProbe_get_Group_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IProbe_put_Group_Proxy( 
    IProbe * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IProbe_put_Group_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IProbe_get_MostRecentDataPoint_Proxy( 
    IProbe * This,
    /* [retval][out] */ IDataPoint **pVal);


void __RPC_STUB IProbe_get_MostRecentDataPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE IProbe_Poll_Proxy( 
    IProbe * This,
    /* [in] */ IDataPoint *pDataPoint);


void __RPC_STUB IProbe_Poll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IProbe_INTERFACE_DEFINED__ */


#ifndef __IProbeCollection_INTERFACE_DEFINED__
#define __IProbeCollection_INTERFACE_DEFINED__

/* interface IProbeCollection */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IProbeCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D9D970B1-1CC5-4455-96B6-8C4ADD87D2B9")
    IProbeCollection : public IDispatch
    {
    public:
        virtual /* [restricted][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ LPUNKNOWN *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IProbe *pProbe) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IDispatch **pItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ItemByNumber( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IDispatch **pItem) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IProbeCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProbeCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProbeCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProbeCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IProbeCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IProbeCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IProbeCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IProbeCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [restricted][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IProbeCollection * This,
            /* [retval][out] */ LPUNKNOWN *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IProbeCollection * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IProbeCollection * This,
            /* [in] */ IProbe *pProbe);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IProbeCollection * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IDispatch **pItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IProbeCollection * This,
            /* [in] */ VARIANT Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IProbeCollection * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ItemByNumber )( 
            IProbeCollection * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IDispatch **pItem);
        
        END_INTERFACE
    } IProbeCollectionVtbl;

    interface IProbeCollection
    {
        CONST_VTBL struct IProbeCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProbeCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IProbeCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IProbeCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IProbeCollection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IProbeCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IProbeCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IProbeCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IProbeCollection_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define IProbeCollection_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define IProbeCollection_Add(This,pProbe)	\
    (This)->lpVtbl -> Add(This,pProbe)

#define IProbeCollection_Item(This,Index,pItem)	\
    (This)->lpVtbl -> Item(This,Index,pItem)

#define IProbeCollection_Remove(This,Index)	\
    (This)->lpVtbl -> Remove(This,Index)

#define IProbeCollection_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define IProbeCollection_ItemByNumber(This,Index,pItem)	\
    (This)->lpVtbl -> ItemByNumber(This,Index,pItem)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [restricted][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IProbeCollection_get__NewEnum_Proxy( 
    IProbeCollection * This,
    /* [retval][out] */ LPUNKNOWN *pVal);


void __RPC_STUB IProbeCollection_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IProbeCollection_get_Count_Proxy( 
    IProbeCollection * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IProbeCollection_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IProbeCollection_Add_Proxy( 
    IProbeCollection * This,
    /* [in] */ IProbe *pProbe);


void __RPC_STUB IProbeCollection_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IProbeCollection_Item_Proxy( 
    IProbeCollection * This,
    /* [in] */ VARIANT Index,
    /* [retval][out] */ IDispatch **pItem);


void __RPC_STUB IProbeCollection_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IProbeCollection_Remove_Proxy( 
    IProbeCollection * This,
    /* [in] */ VARIANT Index);


void __RPC_STUB IProbeCollection_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IProbeCollection_Clear_Proxy( 
    IProbeCollection * This);


void __RPC_STUB IProbeCollection_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IProbeCollection_ItemByNumber_Proxy( 
    IProbeCollection * This,
    /* [in] */ VARIANT Index,
    /* [retval][out] */ IDispatch **pItem);


void __RPC_STUB IProbeCollection_ItemByNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IProbeCollection_INTERFACE_DEFINED__ */


#ifndef __ISensatronicsDevice_INTERFACE_DEFINED__
#define __ISensatronicsDevice_INTERFACE_DEFINED__

/* interface ISensatronicsDevice */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISensatronicsDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C161A699-A412-4800-8BF5-AE49B6361D57")
    ISensatronicsDevice : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ISensatronicsDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISensatronicsDevice * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISensatronicsDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISensatronicsDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISensatronicsDevice * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISensatronicsDevice * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISensatronicsDevice * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISensatronicsDevice * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ISensatronicsDeviceVtbl;

    interface ISensatronicsDevice
    {
        CONST_VTBL struct ISensatronicsDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISensatronicsDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISensatronicsDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISensatronicsDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISensatronicsDevice_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISensatronicsDevice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISensatronicsDevice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISensatronicsDevice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISensatronicsDevice_INTERFACE_DEFINED__ */


#ifndef __ISensatronicsModelE_INTERFACE_DEFINED__
#define __ISensatronicsModelE_INTERFACE_DEFINED__

/* interface ISensatronicsModelE */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISensatronicsModelE;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD319538-236E-4209-9CA5-6291CCC56E58")
    ISensatronicsModelE : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IpAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IpAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Mask( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Mask( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Gateway( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Gateway( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SerialNumber( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SnmpTrapIpAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SnmpTrapIpAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SnmpWriteCommunityString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SnmpWriteCommunityString( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SnmpReadCommunityString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SnmpReadCommunityString( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SoftwareVersion( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SoftwareVersion( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SoftwareReleaseDate( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SoftwareReleaseDate( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Poll( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Model( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Model( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Probe( 
            /* [in] */ SHORT probeId,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Probes( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISensatronicsModelEVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISensatronicsModelE * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISensatronicsModelE * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISensatronicsModelE * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISensatronicsModelE * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISensatronicsModelE * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISensatronicsModelE * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISensatronicsModelE * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IpAddress )( 
            ISensatronicsModelE * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IpAddress )( 
            ISensatronicsModelE * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ISensatronicsModelE * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            ISensatronicsModelE * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Mask )( 
            ISensatronicsModelE * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Mask )( 
            ISensatronicsModelE * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Gateway )( 
            ISensatronicsModelE * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Gateway )( 
            ISensatronicsModelE * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SerialNumber )( 
            ISensatronicsModelE * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SnmpTrapIpAddress )( 
            ISensatronicsModelE * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SnmpTrapIpAddress )( 
            ISensatronicsModelE * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SnmpWriteCommunityString )( 
            ISensatronicsModelE * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SnmpWriteCommunityString )( 
            ISensatronicsModelE * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SnmpReadCommunityString )( 
            ISensatronicsModelE * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SnmpReadCommunityString )( 
            ISensatronicsModelE * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SoftwareVersion )( 
            ISensatronicsModelE * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SoftwareVersion )( 
            ISensatronicsModelE * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SoftwareReleaseDate )( 
            ISensatronicsModelE * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SoftwareReleaseDate )( 
            ISensatronicsModelE * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Poll )( 
            ISensatronicsModelE * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Model )( 
            ISensatronicsModelE * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Model )( 
            ISensatronicsModelE * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Probe )( 
            ISensatronicsModelE * This,
            /* [in] */ SHORT probeId,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Probes )( 
            ISensatronicsModelE * This,
            /* [retval][out] */ IDispatch **pVal);
        
        END_INTERFACE
    } ISensatronicsModelEVtbl;

    interface ISensatronicsModelE
    {
        CONST_VTBL struct ISensatronicsModelEVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISensatronicsModelE_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISensatronicsModelE_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISensatronicsModelE_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISensatronicsModelE_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISensatronicsModelE_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISensatronicsModelE_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISensatronicsModelE_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISensatronicsModelE_get_IpAddress(This,pVal)	\
    (This)->lpVtbl -> get_IpAddress(This,pVal)

#define ISensatronicsModelE_put_IpAddress(This,newVal)	\
    (This)->lpVtbl -> put_IpAddress(This,newVal)

#define ISensatronicsModelE_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define ISensatronicsModelE_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define ISensatronicsModelE_get_Mask(This,pVal)	\
    (This)->lpVtbl -> get_Mask(This,pVal)

#define ISensatronicsModelE_put_Mask(This,newVal)	\
    (This)->lpVtbl -> put_Mask(This,newVal)

#define ISensatronicsModelE_get_Gateway(This,pVal)	\
    (This)->lpVtbl -> get_Gateway(This,pVal)

#define ISensatronicsModelE_put_Gateway(This,newVal)	\
    (This)->lpVtbl -> put_Gateway(This,newVal)

#define ISensatronicsModelE_get_SerialNumber(This,pVal)	\
    (This)->lpVtbl -> get_SerialNumber(This,pVal)

#define ISensatronicsModelE_get_SnmpTrapIpAddress(This,pVal)	\
    (This)->lpVtbl -> get_SnmpTrapIpAddress(This,pVal)

#define ISensatronicsModelE_put_SnmpTrapIpAddress(This,newVal)	\
    (This)->lpVtbl -> put_SnmpTrapIpAddress(This,newVal)

#define ISensatronicsModelE_get_SnmpWriteCommunityString(This,pVal)	\
    (This)->lpVtbl -> get_SnmpWriteCommunityString(This,pVal)

#define ISensatronicsModelE_put_SnmpWriteCommunityString(This,newVal)	\
    (This)->lpVtbl -> put_SnmpWriteCommunityString(This,newVal)

#define ISensatronicsModelE_get_SnmpReadCommunityString(This,pVal)	\
    (This)->lpVtbl -> get_SnmpReadCommunityString(This,pVal)

#define ISensatronicsModelE_put_SnmpReadCommunityString(This,newVal)	\
    (This)->lpVtbl -> put_SnmpReadCommunityString(This,newVal)

#define ISensatronicsModelE_get_SoftwareVersion(This,pVal)	\
    (This)->lpVtbl -> get_SoftwareVersion(This,pVal)

#define ISensatronicsModelE_put_SoftwareVersion(This,newVal)	\
    (This)->lpVtbl -> put_SoftwareVersion(This,newVal)

#define ISensatronicsModelE_get_SoftwareReleaseDate(This,pVal)	\
    (This)->lpVtbl -> get_SoftwareReleaseDate(This,pVal)

#define ISensatronicsModelE_put_SoftwareReleaseDate(This,newVal)	\
    (This)->lpVtbl -> put_SoftwareReleaseDate(This,newVal)

#define ISensatronicsModelE_Poll(This)	\
    (This)->lpVtbl -> Poll(This)

#define ISensatronicsModelE_get_Model(This,pVal)	\
    (This)->lpVtbl -> get_Model(This,pVal)

#define ISensatronicsModelE_put_Model(This,newVal)	\
    (This)->lpVtbl -> put_Model(This,newVal)

#define ISensatronicsModelE_get_Probe(This,probeId,pVal)	\
    (This)->lpVtbl -> get_Probe(This,probeId,pVal)

#define ISensatronicsModelE_get_Probes(This,pVal)	\
    (This)->lpVtbl -> get_Probes(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_get_IpAddress_Proxy( 
    ISensatronicsModelE * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelE_get_IpAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_put_IpAddress_Proxy( 
    ISensatronicsModelE * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISensatronicsModelE_put_IpAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_get_Name_Proxy( 
    ISensatronicsModelE * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelE_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_put_Name_Proxy( 
    ISensatronicsModelE * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISensatronicsModelE_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_get_Mask_Proxy( 
    ISensatronicsModelE * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelE_get_Mask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_put_Mask_Proxy( 
    ISensatronicsModelE * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISensatronicsModelE_put_Mask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_get_Gateway_Proxy( 
    ISensatronicsModelE * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelE_get_Gateway_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_put_Gateway_Proxy( 
    ISensatronicsModelE * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISensatronicsModelE_put_Gateway_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_get_SerialNumber_Proxy( 
    ISensatronicsModelE * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelE_get_SerialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_get_SnmpTrapIpAddress_Proxy( 
    ISensatronicsModelE * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelE_get_SnmpTrapIpAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_put_SnmpTrapIpAddress_Proxy( 
    ISensatronicsModelE * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISensatronicsModelE_put_SnmpTrapIpAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_get_SnmpWriteCommunityString_Proxy( 
    ISensatronicsModelE * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelE_get_SnmpWriteCommunityString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_put_SnmpWriteCommunityString_Proxy( 
    ISensatronicsModelE * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISensatronicsModelE_put_SnmpWriteCommunityString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_get_SnmpReadCommunityString_Proxy( 
    ISensatronicsModelE * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelE_get_SnmpReadCommunityString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_put_SnmpReadCommunityString_Proxy( 
    ISensatronicsModelE * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISensatronicsModelE_put_SnmpReadCommunityString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_get_SoftwareVersion_Proxy( 
    ISensatronicsModelE * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelE_get_SoftwareVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_put_SoftwareVersion_Proxy( 
    ISensatronicsModelE * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISensatronicsModelE_put_SoftwareVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_get_SoftwareReleaseDate_Proxy( 
    ISensatronicsModelE * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelE_get_SoftwareReleaseDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_put_SoftwareReleaseDate_Proxy( 
    ISensatronicsModelE * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISensatronicsModelE_put_SoftwareReleaseDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_Poll_Proxy( 
    ISensatronicsModelE * This);


void __RPC_STUB ISensatronicsModelE_Poll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_get_Model_Proxy( 
    ISensatronicsModelE * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelE_get_Model_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_put_Model_Proxy( 
    ISensatronicsModelE * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISensatronicsModelE_put_Model_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_get_Probe_Proxy( 
    ISensatronicsModelE * This,
    /* [in] */ SHORT probeId,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB ISensatronicsModelE_get_Probe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelE_get_Probes_Proxy( 
    ISensatronicsModelE * This,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB ISensatronicsModelE_get_Probes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISensatronicsModelE_INTERFACE_DEFINED__ */


#ifndef __ISensatronicsModelF_INTERFACE_DEFINED__
#define __ISensatronicsModelF_INTERFACE_DEFINED__

/* interface ISensatronicsModelF */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISensatronicsModelF;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD8DC350-050D-4E20-B9CA-66885E12D851")
    ISensatronicsModelF : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ComPort( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ComPort( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BatteryStatus( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE Poll( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Model( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Probe( 
            /* [in] */ SHORT probeId,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Probes( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISensatronicsModelFVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISensatronicsModelF * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISensatronicsModelF * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISensatronicsModelF * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISensatronicsModelF * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISensatronicsModelF * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISensatronicsModelF * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISensatronicsModelF * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ComPort )( 
            ISensatronicsModelF * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ComPort )( 
            ISensatronicsModelF * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BatteryStatus )( 
            ISensatronicsModelF * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ISensatronicsModelF * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            ISensatronicsModelF * This,
            /* [in] */ BSTR newVal);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Poll )( 
            ISensatronicsModelF * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Model )( 
            ISensatronicsModelF * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Probe )( 
            ISensatronicsModelF * This,
            /* [in] */ SHORT probeId,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Probes )( 
            ISensatronicsModelF * This,
            /* [retval][out] */ IDispatch **pVal);
        
        END_INTERFACE
    } ISensatronicsModelFVtbl;

    interface ISensatronicsModelF
    {
        CONST_VTBL struct ISensatronicsModelFVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISensatronicsModelF_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISensatronicsModelF_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISensatronicsModelF_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISensatronicsModelF_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISensatronicsModelF_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISensatronicsModelF_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISensatronicsModelF_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISensatronicsModelF_get_ComPort(This,pVal)	\
    (This)->lpVtbl -> get_ComPort(This,pVal)

#define ISensatronicsModelF_put_ComPort(This,newVal)	\
    (This)->lpVtbl -> put_ComPort(This,newVal)

#define ISensatronicsModelF_get_BatteryStatus(This,pVal)	\
    (This)->lpVtbl -> get_BatteryStatus(This,pVal)

#define ISensatronicsModelF_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define ISensatronicsModelF_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define ISensatronicsModelF_Poll(This)	\
    (This)->lpVtbl -> Poll(This)

#define ISensatronicsModelF_get_Model(This,pVal)	\
    (This)->lpVtbl -> get_Model(This,pVal)

#define ISensatronicsModelF_get_Probe(This,probeId,pVal)	\
    (This)->lpVtbl -> get_Probe(This,probeId,pVal)

#define ISensatronicsModelF_get_Probes(This,pVal)	\
    (This)->lpVtbl -> get_Probes(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelF_get_ComPort_Proxy( 
    ISensatronicsModelF * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelF_get_ComPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelF_put_ComPort_Proxy( 
    ISensatronicsModelF * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISensatronicsModelF_put_ComPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelF_get_BatteryStatus_Proxy( 
    ISensatronicsModelF * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelF_get_BatteryStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelF_get_Name_Proxy( 
    ISensatronicsModelF * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelF_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelF_put_Name_Proxy( 
    ISensatronicsModelF * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISensatronicsModelF_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelF_Poll_Proxy( 
    ISensatronicsModelF * This);


void __RPC_STUB ISensatronicsModelF_Poll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelF_get_Model_Proxy( 
    ISensatronicsModelF * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ISensatronicsModelF_get_Model_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelF_get_Probe_Proxy( 
    ISensatronicsModelF * This,
    /* [in] */ SHORT probeId,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB ISensatronicsModelF_get_Probe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISensatronicsModelF_get_Probes_Proxy( 
    ISensatronicsModelF * This,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB ISensatronicsModelF_get_Probes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISensatronicsModelF_INTERFACE_DEFINED__ */



#ifndef __SensatronicsSDKLib_LIBRARY_DEFINED__
#define __SensatronicsSDKLib_LIBRARY_DEFINED__

/* library SensatronicsSDKLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SensatronicsSDKLib;

#ifndef ___IDataConnectorEvents_DISPINTERFACE_DEFINED__
#define ___IDataConnectorEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IDataConnectorEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IDataConnectorEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3C73CEAF-C846-4701-B113-68471A2D34A6")
    _IDataConnectorEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IDataConnectorEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDataConnectorEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDataConnectorEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDataConnectorEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IDataConnectorEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IDataConnectorEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IDataConnectorEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IDataConnectorEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IDataConnectorEventsVtbl;

    interface _IDataConnectorEvents
    {
        CONST_VTBL struct _IDataConnectorEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDataConnectorEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IDataConnectorEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IDataConnectorEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IDataConnectorEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IDataConnectorEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IDataConnectorEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IDataConnectorEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDataConnectorEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_DataConnector;

#ifdef __cplusplus

class DECLSPEC_UUID("36EFA26D-CC3A-43F7-81AE-E5F016E656DA")
DataConnector;
#endif

#ifndef ___IDataPointEvents_DISPINTERFACE_DEFINED__
#define ___IDataPointEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IDataPointEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IDataPointEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00BF7714-BDA8-4FD5-8F36-FA31902F3EAF")
    _IDataPointEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IDataPointEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDataPointEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDataPointEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDataPointEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IDataPointEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IDataPointEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IDataPointEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IDataPointEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IDataPointEventsVtbl;

    interface _IDataPointEvents
    {
        CONST_VTBL struct _IDataPointEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDataPointEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IDataPointEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IDataPointEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IDataPointEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IDataPointEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IDataPointEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IDataPointEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDataPointEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_DataPoint;

#ifdef __cplusplus

class DECLSPEC_UUID("1A24868D-99B3-466A-905A-485A5DB889B8")
DataPoint;
#endif

#ifndef ___IProbeEvents_DISPINTERFACE_DEFINED__
#define ___IProbeEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IProbeEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IProbeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4363E570-FB21-40C4-8DD5-181D81706101")
    _IProbeEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IProbeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IProbeEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IProbeEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IProbeEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IProbeEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IProbeEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IProbeEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IProbeEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IProbeEventsVtbl;

    interface _IProbeEvents
    {
        CONST_VTBL struct _IProbeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IProbeEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IProbeEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IProbeEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IProbeEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IProbeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IProbeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IProbeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IProbeEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Probe;

#ifdef __cplusplus

class DECLSPEC_UUID("0C10DB5E-A4FE-4A07-9273-2BA5D82A632B")
Probe;
#endif

EXTERN_C const CLSID CLSID_ProbeCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("AA4B7260-B2F1-4DDF-98EF-EB89785B3D60")
ProbeCollection;
#endif

#ifndef ___ISensatronicsModelEEvents_DISPINTERFACE_DEFINED__
#define ___ISensatronicsModelEEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ISensatronicsModelEEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ISensatronicsModelEEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("ED3B1F88-E952-4B41-896E-D6E94DF78310")
    _ISensatronicsModelEEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ISensatronicsModelEEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ISensatronicsModelEEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ISensatronicsModelEEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ISensatronicsModelEEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ISensatronicsModelEEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ISensatronicsModelEEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ISensatronicsModelEEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ISensatronicsModelEEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _ISensatronicsModelEEventsVtbl;

    interface _ISensatronicsModelEEvents
    {
        CONST_VTBL struct _ISensatronicsModelEEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ISensatronicsModelEEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ISensatronicsModelEEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ISensatronicsModelEEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ISensatronicsModelEEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ISensatronicsModelEEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ISensatronicsModelEEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ISensatronicsModelEEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ISensatronicsModelEEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SensatronicsModelE;

#ifdef __cplusplus

class DECLSPEC_UUID("D0C00F42-F307-47E3-A2BE-084E1EB1871E")
SensatronicsModelE;
#endif

#ifndef ___ISensatronicsModelFEvents_DISPINTERFACE_DEFINED__
#define ___ISensatronicsModelFEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ISensatronicsModelFEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ISensatronicsModelFEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2457F1C9-1B32-4B37-A661-041D9D66F770")
    _ISensatronicsModelFEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ISensatronicsModelFEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ISensatronicsModelFEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ISensatronicsModelFEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ISensatronicsModelFEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ISensatronicsModelFEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ISensatronicsModelFEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ISensatronicsModelFEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ISensatronicsModelFEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _ISensatronicsModelFEventsVtbl;

    interface _ISensatronicsModelFEvents
    {
        CONST_VTBL struct _ISensatronicsModelFEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ISensatronicsModelFEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ISensatronicsModelFEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ISensatronicsModelFEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ISensatronicsModelFEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ISensatronicsModelFEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ISensatronicsModelFEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ISensatronicsModelFEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ISensatronicsModelFEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SensatronicsModelF;

#ifdef __cplusplus

class DECLSPEC_UUID("1D9215AF-6E08-426F-8095-893DD0D38D60")
SensatronicsModelF;
#endif
#endif /* __SensatronicsSDKLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


