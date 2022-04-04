#include "Rhine.h"

class App : public Rhine::Application
{
public:
	App()
	{

	}
	~App()
	{

	}
};

Rhine::Application* Rhine::CreateApplication()
{
	return new App();
}
