#include "Rhine.h"

class App : public Rhine::DXApp
{
public:
	App()
	{

	}
	~App()
	{

	}
};

Rhine::DXApp* Rhine::CreateDXApp()
{
	return new App();
}
