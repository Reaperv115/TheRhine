#include "RenderWindow.h"

RenderWindow::RenderWindow()
{
	RegisterWindow();
	handle = CreateWindowEx(0, windowclassName.c_str(), windowName.c_str(), style, 0, 0, 900, 700, NULL, NULL, hInst, nullptr);
	graphics.InitializeDirectX(handle);
	ShowWindow(handle, SW_SHOW);
	SetForegroundWindow(handle);
	SetFocus(handle);
}

void RenderWindow::RegisterWindow()
{
	WNDCLASSEX wc;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = windowclassName.c_str();
	wc.cbSize = sizeof(WNDCLASSEX);
	RegisterClassEx(&wc);
}

void RenderWindow::Render()
{
	
	graphics.Render();
}

HWND RenderWindow::getHandle()
{
	return handle;
}

HINSTANCE RenderWindow::getInstance()
{
	return hInst;
}

bool RenderWindow::ProcessMessages()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	if (PeekMessage(&msg, handle, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (msg.message == WM_NULL)
	{
		if (!IsWindow(handle))
		{
			handle = NULL;
			UnregisterClass(windowclassName.c_str(), hInst);
			return false;
		}
	}
	return true;
}
