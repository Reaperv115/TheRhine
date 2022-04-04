#include "DXApp.h"

namespace Rhine
{
	DXApp::DXApp()
	{}
	DXApp::DXApp(HINSTANCE hInst)
	{
		mAppInst = hInst;
	}

	DXApp::~DXApp()
	{

	}

	void DXApp::Run()
	{
		while (true);
	}
	void DXApp::InitializeDirectX()
	{
	}
	void DXApp::Render()
	{
	}
}