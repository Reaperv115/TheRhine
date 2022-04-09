#include "DXApp.h"

namespace Rhine
{
	struct Vertex
	{
		XMFLOAT2 pos;
	};

	struct Triangle
	{
		Vertex positions[3];
	};

	

	class Application : public DXApp
	{

	public:
		Application();
		Application(std::wstring className, std::wstring WindowName);
		void Init();
		bool UpdateScene();
		void DrawScene();
		~Application();


	};

	Application::Application(std::wstring className, std::wstring WindowName)
	{
		windowclassName = className;
		windowName = WindowName;
		Init();
	}


	void Application::Init()
	{
		AllocConsole();
		InitMainWindow();
		InitializeDirectX();
	}

	Application::~Application()
	{
	}

	bool Application::UpdateScene()
	{
		return true;
	}
	void Application::DrawScene()
	{
		Render();
	}

}

int wWinMain(HINSTANCE hInst,
	HINSTANCE hprevInst,
	LPWSTR cmdLine,
	int cmdShow)
{
	Rhine::Application app(L"The Rhine", L"Engine");
	return app.Run();

}


