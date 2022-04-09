#pragma once
#include "TriangleVS.csh"

#include <sstream>
#include <d3d11.h>
#include <DirectXMath.h>
#include <iostream>

#include "StringConverter.h"
#include "GameTimer.h"

using namespace DirectX;

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "DirectXTK.lib")

namespace Rhine
{
	class DXApp
	{
	public:
		DXApp();
		DXApp(HINSTANCE hInst);
		virtual ~DXApp();

		HINSTANCE AppInst() const;
		HWND GetMainWnd() const;
		float AspectRatio() const;

		int Run();

		virtual void Init();
		virtual bool OnResize();
		virtual bool UpdateScene() = 0;
		virtual void DrawScene() = 0;
		virtual LRESULT MsgProch(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	protected:
		bool InitMainWindow();
		void CalculateFrameStats();
		void RegisterWindow();

	protected:
		HINSTANCE mAppInst; //application instance handle
		HWND mMainWnd;		//main window handle
		DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
		bool mAppPaused;	//is the app paused
		bool mMinimized;	// is the window minimized
		bool mMaximized;	// is the window maximized
		bool mResizing;		// is the window being resized

		void InitializeDirectX();
		void InitializeScene();
		void Render();

		ID3D11Device* device;
		ID3D11DeviceContext* deviceContext;
		IDXGISwapChain* swapChain;
		ID3D11InputLayout* itriangleLayout;
		ID3D11VertexShader* triangleVS;
		ID3D11PixelShader* trianglePS;
		DXGI_SWAP_CHAIN_DESC swapchainDesc;
		ID3D11RenderTargetView* rendertargetView;
		ID3D11Texture2D* backBuffer;
		D3D11_VIEWPORT viewPort;
		std::wstring mMwndCaption;
		GameTimer gametimer;

		std::wstring windowclassName, windowName;
		LPCWSTR messageboxMssge, messageboxTitle;

		int width = 900, height = 700;


	};
}

