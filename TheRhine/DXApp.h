#pragma once
#include <d3d11.h>
#include "Triangle.h"
class DXApp
{
public:
	DXApp();
	DXApp(HINSTANCE hInst);
	virtual ~DXApp();

	HINSTANCE AppInst() const;
	HWND MainWnd() const;
	float AspectRatio() const;

	int Run();

	virtual bool Init();
	virtual bool OnResize();
	virtual bool UpdateScene(float dt) = 0;
	virtual void DrawScene() = 0;
	virtual LRESULT MsgProch(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

protected:
	bool InitMainWindow();
	void CalculateFrameStats();

protected:
	HINSTANCE mAppInst; //application instance handle
	HWND mMainWnd;		//main window handle
	bool mAppPaused;	//is the app paused
	bool mMinimized;	// is the window minimized
	bool mMaximized;	// is the window maximized
	bool mResizing;		// is the window being resized

	void InitializeDirectX(HWND hwnd);
	void InitializeScene();
	void Render();

	ID3D11Device* device;
	ID3D11DeviceContext* deviceContext;
	IDXGISwapChain* swapChain;
	DXGI_SWAP_CHAIN_DESC swapchainDesc;
	ID3D11RenderTargetView* rendertargetView;
	ID3D11Texture2D* backBuffer;
	D3D11_VIEWPORT viewPort;
	Triangle triangle;

	int width = 900, height = 700;


};

