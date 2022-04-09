#include "Rhine.h"

class App : public Rhine::DXApp
{
public:
	App();
	App(std::wstring className, std::wstring menuName);
	~App();
	void Init();
	void Run();
};

App::App()
{

}

App::App(std::wstring className, std::wstring menuName)
{
	windowclassName = className;
	windowmenuName = menuName;
}

App::~App()
{

}

void App::Init()
{
	InitMainWindow();
	InitializeDirectX();
}

void App::Run()
{
	Render();
}

Rhine::DXApp* Rhine::CreateDXApp()
{
	return new App();
}

int wWinMain(HINSTANCE hInst, HINSTANCE hprevInst, LPWSTR cmdLine, int cmdShow)
{
	App app(L"The Rhine", L"Engine");
	app.Run();

	return 0;
}