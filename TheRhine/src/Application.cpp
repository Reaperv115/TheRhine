#include "rpch.h"
#include "Application.h"

namespace Rhine
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}
	LRESULT WindowProcess(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
		default:
			break;
		}
		return DefWindowProc(handle, message, wParam, lParam);
	}
	void Application::InitWindow(HINSTANCE hInst)
	{

		WNDCLASSEX wc;
		ZeroMemory(&wc, sizeof(wc));
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = WindowProcess;
		wc.lpszClassName = L"The Rhine";
		wc.hInstance = hInst;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		RegisterClassEx(&wc);
		windowhandle = CreateWindowEx(0, L"The Rhine", L"Engine", WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 1000, 300, width, height, nullptr, nullptr, hInst, nullptr);
		if (!windowhandle)
		{
			MessageBox(windowhandle, L"Failed to create window!", L"ERROR", 0);
		}
		ShowWindow(windowhandle, SW_SHOW);

		InitializeDirectX();
		InitializeScene();
	}

	void Application::Run()
	{
		MSG msg = { 0 };
		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				Render();
			}
		}
	}
}

