#pragma once
#include <dxgi.h>

#pragma comment(lib, "dxgi.lib")


#include "Shaders/VertexShader.h"
#include "Shaders/PixelShader.h"



namespace Rhine
{
	class DXApp
	{
	public:
		DXApp();
		~DXApp();
		void InitializeDirectX();
		void InitializeScene();
		void Render();
		HWND GetWindowHandle() const;

		HWND windowhandle;

		ID3D11Device* device;
		ID3D11DeviceContext* deviceContext;
		IDXGISwapChain* swapChain;
		DXGI_SWAP_CHAIN_DESC swapchainDesc;
		ID3D11RenderTargetView* rendertargetView;
		ID3D11Texture2D* backBuffer;
		D3D11_VIEWPORT viewPort;
		D3D11_BUFFER_DESC bufferDesc;
		D3D11_SUBRESOURCE_DATA subresource;
		ID3D11Buffer* vertexBuffer;
		IDXGIFactory* factoryInst;

		ID3D11InputLayout* ilayOut;
		UINT stride;
		UINT offset = 0;
		VertexShader vShader;
		PixelShader pShader;
		ID3D10Blob* blob;

		int width = 1000;
		int height = 500;
	};
}

