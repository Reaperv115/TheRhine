#pragma once
#include <d3d11.h>
#include "Triangle.h"
class DXApp
{
	ID3D11Device* device;
	ID3D11DeviceContext* deviceContext;
	IDXGISwapChain* swapChain;
	DXGI_SWAP_CHAIN_DESC swapchainDesc;
	ID3D11RenderTargetView* rendertargetView;
	ID3D11Texture2D* backBuffer;
	D3D11_VIEWPORT viewPort;
	Triangle triangle;

	int width = 900, height = 700;

public:
	DXApp();
	~DXApp();
	void InitializeDirectX(HWND hwnd);
	void InitializeScene();
	void Render();
};

