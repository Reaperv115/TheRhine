#include "Rhine.h"

class App : public Rhine::DXApp
{
public:
	App();
	~App();

	void Run();
};

App::App()
{

}

App::~App()
{

}

void App::Run()
{
	Render();
}

Rhine::DXApp* Rhine::CreateDXApp()
{
	return new App();
}
