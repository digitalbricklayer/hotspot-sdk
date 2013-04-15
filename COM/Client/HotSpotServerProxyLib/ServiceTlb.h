#pragma once

#if defined(DEBUG)
#import "../../SensatronicsSDK/SensatronicsSDK/Debug/SensatronicsSDK.tlb" named_guids rename_namespace("ox")
#elif defined(NDEBUG)
#import "../../SensatronicsSDK/SensatronicsSDK/Release/SensatronicsSDK.tlb" named_guids rename_namespace("ox")
#else
#error Either DEBUG or NDEBUG must be defined
#endif

#if defined(DEBUG)
#import "..\..\SensatronicsSDK\MockSensors\Debug\MockSensors.tlb" named_guids
#elif defined(NDEBUG)
#import "..\..\SensatronicsSDK\MockSensors\Release\MockSensors.tlb" named_guids
#else
#error Either DEBUG or NDEBUG must be defined
#endif
