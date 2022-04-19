#include "Application.h"


int wWinMain(_In_ HINSTANCE hInst, _In_ HINSTANCE hPrevInst, _In_ LPWSTR CmdLine, _In_ int CmdShow)
{
	Rhine::Application* app = new Rhine::Application();
	app->InitWindow(hInst);
	app->Run();
	delete app;
	return 0;
}