#pragma once
#include <Windows.h>
#include "StringConverter.h"
#include "Graphics.h"

class RenderWindow
{
	HINSTANCE hInst;
	HWND handle;
	std::wstring windowclassName = StringConverter::StringtoWide("The Rhine");
	std::wstring windowName = StringConverter::StringtoWide("Engine");
	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
	int width = 900;
	int height = 700;
	Graphics graphics;

public:
	RenderWindow();
	bool ProcessMessages();
	void Render();
	HWND getHandle();
	HINSTANCE getInstance();
private:
	void RegisterWindow();
};

