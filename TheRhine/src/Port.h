#pragma once

#ifdef TR_PLATFORM_WINDOWS
#ifdef BUILD_DLL
#define RHINE_API __declspec(dllexport)
#else
#define RHINE_API __declspec(dllimport)
#endif // BUILD_DLL

#endif // TR_PLATFORM_WINDOWS
