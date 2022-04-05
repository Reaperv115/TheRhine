#include "DXApp.h"

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


	int wWinMain(HINSTANCE hInst,
		HINSTANCE hprevInst,
		LPWSTR cmdLine,
		int cmdShow)
	{
		Application app(L"The Rhine", L"Engine");
		return app.Run();

		return 0;
	}

	Application::Application(std::wstring className, std::wstring WindowName)
	{
		windowclassName = className;
		windowName = WindowName;
		Init();
	}


	void Application::Init()
	{
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




