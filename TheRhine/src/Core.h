#pragma once

#ifdef TR_PLATFORM_WINDOWS
#ifdef TR_BUILD_DLL
#define RHINE_API __declspec(dllexport)
#else
#define RHINE_API	__declspec(dllimport)
#endif // TR_BUILD_DLL

#endif // TR_PLATFORM_WINDOWS
