#pragma once
#include "Core.h"

namespace Rhine
{
	class RHINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

