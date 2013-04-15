

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */
#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "MockSensors.h"

#define TYPE_FORMAT_STRING_SIZE   63                                
#define PROC_FORMAT_STRING_SIZE   239                               
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMockSensor_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMockSensor_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure AddSensor */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 10 */	NdrFcShort( 0x10 ),	/* 16 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x5,		/* 5 */

	/* Parameter SensorId */

/* 16 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 18 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 20 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter ConfigData */

/* 22 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 24 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 26 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter PollData */

/* 28 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 30 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 32 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter Time */

/* 34 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 36 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 38 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 40 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 42 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 44 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddSensorPollData */

/* 46 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 48 */	NdrFcLong( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x8 ),	/* 8 */
/* 54 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 56 */	NdrFcShort( 0x10 ),	/* 16 */
/* 58 */	NdrFcShort( 0x8 ),	/* 8 */
/* 60 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter SensorId */

/* 62 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 64 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 66 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter PollData */

/* 68 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 70 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 72 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter Time */

/* 74 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 76 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 78 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 80 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 82 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 84 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSensorPollData */

/* 86 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 88 */	NdrFcLong( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x9 ),	/* 9 */
/* 94 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x8 ),	/* 8 */
/* 100 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter SensorId */

/* 102 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 104 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 106 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter PollData */

/* 108 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 110 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 112 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */

/* 114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 116 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_PollCount */

/* 120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0xa ),	/* 10 */
/* 128 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0x24 ),	/* 36 */
/* 134 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 136 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 138 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 142 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 144 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_PollCount */

/* 148 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 150 */	NdrFcLong( 0x0 ),	/* 0 */
/* 154 */	NdrFcShort( 0xb ),	/* 11 */
/* 156 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 162 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 164 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 166 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 170 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 172 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSensorConfigData */

/* 176 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0xc ),	/* 12 */
/* 184 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 190 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter SensorId */

/* 192 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 194 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 196 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter ConfigData */

/* 198 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 200 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 202 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */

/* 204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 206 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTimeStamp */

/* 210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0xd ),	/* 13 */
/* 218 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x2c ),	/* 44 */
/* 224 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter TimeStamp */

/* 226 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 228 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 230 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 232 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 234 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x12, 0x0,	/* FC_UP */
/*  4 */	NdrFcShort( 0xc ),	/* Offset= 12 (16) */
/*  6 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/*  8 */	NdrFcShort( 0x2 ),	/* 2 */
/* 10 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 12 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 14 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 16 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 18 */	NdrFcShort( 0x8 ),	/* 8 */
/* 20 */	NdrFcShort( 0xfff2 ),	/* Offset= -14 (6) */
/* 22 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 24 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 26 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */
/* 30 */	NdrFcShort( 0x4 ),	/* 4 */
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (2) */
/* 36 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 38 */	NdrFcShort( 0x6 ),	/* Offset= 6 (44) */
/* 40 */	
			0x13, 0x0,	/* FC_OP */
/* 42 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (16) */
/* 44 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x4 ),	/* 4 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (40) */
/* 54 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 56 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 58 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 60 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IMockSensor, ver. 0.0,
   GUID={0x944265C7,0x0F32,0x4E05,{0x80,0x7B,0xC7,0x73,0xDF,0x61,0x84,0xD9}} */

#pragma code_seg(".orpc")
static const unsigned short IMockSensor_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    46,
    86,
    120,
    148,
    176,
    210
    };

static const MIDL_STUBLESS_PROXY_INFO IMockSensor_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IMockSensor_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMockSensor_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IMockSensor_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IMockSensorProxyVtbl = 
{
    &IMockSensor_ProxyInfo,
    &IID_IMockSensor,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMockSensor::AddSensor */ ,
    (void *) (INT_PTR) -1 /* IMockSensor::AddSensorPollData */ ,
    (void *) (INT_PTR) -1 /* IMockSensor::GetSensorPollData */ ,
    (void *) (INT_PTR) -1 /* IMockSensor::get_PollCount */ ,
    (void *) (INT_PTR) -1 /* IMockSensor::put_PollCount */ ,
    (void *) (INT_PTR) -1 /* IMockSensor::GetSensorConfigData */ ,
    (void *) (INT_PTR) -1 /* IMockSensor::GetTimeStamp */
};


static const PRPC_STUB_FUNCTION IMockSensor_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMockSensorStubVtbl =
{
    &IID_IMockSensor,
    &IMockSensor_ServerInfo,
    14,
    &IMockSensor_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x600016e, /* MIDL Version 6.0.366 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _MockSensors_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IMockSensorProxyVtbl,
    0
};

const CInterfaceStubVtbl * _MockSensors_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IMockSensorStubVtbl,
    0
};

PCInterfaceName const _MockSensors_InterfaceNamesList[] = 
{
    "IMockSensor",
    0
};

const IID *  _MockSensors_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _MockSensors_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _MockSensors, pIID, n)

int __stdcall _MockSensors_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_MockSensors_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo MockSensors_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _MockSensors_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _MockSensors_StubVtblList,
    (const PCInterfaceName * ) & _MockSensors_InterfaceNamesList,
    (const IID ** ) & _MockSensors_BaseIIDList,
    & _MockSensors_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

