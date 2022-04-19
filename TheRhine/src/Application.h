#pragma once
#include <Windows.h>

#include "Port.h"

#include "DXApp.h"

namespace Rhine
{
	class RHINE_API Application : public DXApp
	{
	public:
		Application();
		~Application();


		HINSTANCE appInst;

		void InitWindow(HINSTANCE hInst);
		void Run();
	};
}

