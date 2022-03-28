#include <Windows.h>
#include <iostream>
#include "RenderWindow.h"
#include "Graphics.h"
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "DirectXTK.lib")

class Application
{
	int APIENTRY wWinMain(_In_ HINSTANCE hInst,
		_In_opt_ HINSTANCE hprevInst,
		_In_ LPWSTR cmdLine,
		_In_ int cmdShow)
	{

		RenderWindow rw;
		while (rw.ProcessMessages())
		{
			rw.Render();
		}
		return 0;
	}
};



