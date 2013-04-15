

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Fri Dec 01 11:16:18 2006
 */
/* Compiler settings for .\MockSensors.idl:
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

#ifndef __MockSensors_h__
#define __MockSensors_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMockSensor_FWD_DEFINED__
#define __IMockSensor_FWD_DEFINED__
typedef interface IMockSensor IMockSensor;
#endif 	/* __IMockSensor_FWD_DEFINED__ */


#ifndef __MockSensor_FWD_DEFINED__
#define __MockSensor_FWD_DEFINED__

#ifdef __cplusplus
typedef class MockSensor MockSensor;
#else
typedef struct MockSensor MockSensor;
#endif /* __cplusplus */

#endif 	/* __MockSensor_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IMockSensor_INTERFACE_DEFINED__
#define __IMockSensor_INTERFACE_DEFINED__

/* interface IMockSensor */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMockSensor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("944265C7-0F32-4E05-807B-C773DF6184D9")
    IMockSensor : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddSensor( 
            /* [in] */ BSTR SensorId,
            /* [in] */ BSTR ConfigData,
            /* [in] */ BSTR PollData,
            /* [in] */ DATE Time) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddSensorPollData( 
            /* [in] */ BSTR SensorId,
            /* [in] */ BSTR PollData,
            /* [in] */ DATE Time) = 0;
        
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSensorPollData( 
            /* [in] */ BSTR SensorId,
            /* [retval][out] */ BSTR *PollData) = 0;
        
        virtual /* [hidden][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PollCount( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PollCount( 
            /* [in] */ ULONG newVal) = 0;
        
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSensorConfigData( 
            /* [in] */ BSTR SensorId,
            /* [retval][out] */ BSTR *ConfigData) = 0;
        
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTimeStamp( 
            /* [retval][out] */ DATE *TimeStamp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMockSensorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMockSensor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMockSensor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMockSensor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMockSensor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMockSensor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMockSensor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMockSensor * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddSensor )( 
            IMockSensor * This,
            /* [in] */ BSTR SensorId,
            /* [in] */ BSTR ConfigData,
            /* [in] */ BSTR PollData,
            /* [in] */ DATE Time);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddSensorPollData )( 
            IMockSensor * This,
            /* [in] */ BSTR SensorId,
            /* [in] */ BSTR PollData,
            /* [in] */ DATE Time);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSensorPollData )( 
            IMockSensor * This,
            /* [in] */ BSTR SensorId,
            /* [retval][out] */ BSTR *PollData);
        
        /* [hidden][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PollCount )( 
            IMockSensor * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PollCount )( 
            IMockSensor * This,
            /* [in] */ ULONG newVal);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSensorConfigData )( 
            IMockSensor * This,
            /* [in] */ BSTR SensorId,
            /* [retval][out] */ BSTR *ConfigData);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTimeStamp )( 
            IMockSensor * This,
            /* [retval][out] */ DATE *TimeStamp);
        
        END_INTERFACE
    } IMockSensorVtbl;

    interface IMockSensor
    {
        CONST_VTBL struct IMockSensorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMockSensor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMockSensor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMockSensor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMockSensor_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMockSensor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMockSensor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMockSensor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMockSensor_AddSensor(This,SensorId,ConfigData,PollData,Time)	\
    (This)->lpVtbl -> AddSensor(This,SensorId,ConfigData,PollData,Time)

#define IMockSensor_AddSensorPollData(This,SensorId,PollData,Time)	\
    (This)->lpVtbl -> AddSensorPollData(This,SensorId,PollData,Time)

#define IMockSensor_GetSensorPollData(This,SensorId,PollData)	\
    (This)->lpVtbl -> GetSensorPollData(This,SensorId,PollData)

#define IMockSensor_get_PollCount(This,pVal)	\
    (This)->lpVtbl -> get_PollCount(This,pVal)

#define IMockSensor_put_PollCount(This,newVal)	\
    (This)->lpVtbl -> put_PollCount(This,newVal)

#define IMockSensor_GetSensorConfigData(This,SensorId,ConfigData)	\
    (This)->lpVtbl -> GetSensorConfigData(This,SensorId,ConfigData)

#define IMockSensor_GetTimeStamp(This,TimeStamp)	\
    (This)->lpVtbl -> GetTimeStamp(This,TimeStamp)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMockSensor_AddSensor_Proxy( 
    IMockSensor * This,
    /* [in] */ BSTR SensorId,
    /* [in] */ BSTR ConfigData,
    /* [in] */ BSTR PollData,
    /* [in] */ DATE Time);


void __RPC_STUB IMockSensor_AddSensor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMockSensor_AddSensorPollData_Proxy( 
    IMockSensor * This,
    /* [in] */ BSTR SensorId,
    /* [in] */ BSTR PollData,
    /* [in] */ DATE Time);


void __RPC_STUB IMockSensor_AddSensorPollData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE IMockSensor_GetSensorPollData_Proxy( 
    IMockSensor * This,
    /* [in] */ BSTR SensorId,
    /* [retval][out] */ BSTR *PollData);


void __RPC_STUB IMockSensor_GetSensorPollData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMockSensor_get_PollCount_Proxy( 
    IMockSensor * This,
    /* [retval][out] */ ULONG *pVal);


void __RPC_STUB IMockSensor_get_PollCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMockSensor_put_PollCount_Proxy( 
    IMockSensor * This,
    /* [in] */ ULONG newVal);


void __RPC_STUB IMockSensor_put_PollCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE IMockSensor_GetSensorConfigData_Proxy( 
    IMockSensor * This,
    /* [in] */ BSTR SensorId,
    /* [retval][out] */ BSTR *ConfigData);


void __RPC_STUB IMockSensor_GetSensorConfigData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE IMockSensor_GetTimeStamp_Proxy( 
    IMockSensor * This,
    /* [retval][out] */ DATE *TimeStamp);


void __RPC_STUB IMockSensor_GetTimeStamp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMockSensor_INTERFACE_DEFINED__ */



#ifndef __MockSensorsLib_LIBRARY_DEFINED__
#define __MockSensorsLib_LIBRARY_DEFINED__

/* library MockSensorsLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MockSensorsLib;

EXTERN_C const CLSID CLSID_MockSensor;

#ifdef __cplusplus

class DECLSPEC_UUID("AA6B2C3E-C8C4-4733-9205-C56FA3B58719")
MockSensor;
#endif
#endif /* __MockSensorsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


