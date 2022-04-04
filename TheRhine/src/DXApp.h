#pragma once
#include <d3d11.h>
#include <iostream>
#include "Core.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "DirectXTK.lib")

namespace Rhine
{
	class RHINE_API DXApp
	{
	public:
		DXApp();
		DXApp(HINSTANCE hInst);
		virtual ~DXApp();

		void Run();

	protected:
		HINSTANCE mAppInst;
		HWND mMainWnd;
		DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

		void InitializeDirectX();
		void InitializeScene();
		void Render();

		ID3D11Device* device;
		ID3D11DeviceContext* deviceContext;
		IDXGISwapChain* swapChain;
		DXGI_SWAP_CHAIN_DESC swapchainDesc;
		ID3D11RenderTargetView* rendertargetView;
		ID3D11Texture2D* backBuffer;
		D3D11_VIEWPORT viewPort;
		std::wstring mMwndCaption;

		std::wstring windowclassName;
		std::wstring windowName;

		int width = 900, height = 700;
	};

	DXApp* CreateDXApp();
}

