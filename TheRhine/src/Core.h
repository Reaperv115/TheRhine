#pragma once

#ifdef BUILD_DLL
#define RHINE_API __declspec(dllexport)
#else
#define RHINE_API __declspec(dllimport)
#endif // BUILD_DLL
