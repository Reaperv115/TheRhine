#include "DXApp.h"

DXApp::DXApp()
{
}

DXApp::~DXApp()
{
	swapChain->Release();
	device->Release();
	deviceContext->Release();
	rendertargetView->Release();
}

void DXApp::InitializeDirectX(HWND hwnd)
{
	ZeroMemory(&swapchainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
	swapchainDesc.BufferDesc.Width = width;
	swapchainDesc.BufferDesc.Height = height;
	swapchainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapchainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapchainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapchainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapchainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	swapchainDesc.SampleDesc.Count = 1;
	swapchainDesc.SampleDesc.Quality = 0;
	swapchainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapchainDesc.BufferCount = 1;
	swapchainDesc.OutputWindow = hwnd;
	swapchainDesc.Windowed = true;
	swapchainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapchainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	HRESULT hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, D3D11_CREATE_DEVICE_DEBUG, NULL, NULL, D3D11_SDK_VERSION, &swapchainDesc, &swapChain, &device, NULL, &deviceContext);

	swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);
	device->CreateRenderTargetView(backBuffer, NULL, &rendertargetView);
	ID3D11RenderTargetView* newrendertargetView[] = { rendertargetView };
	backBuffer->Release();

	device->CreateRenderTargetView(backBuffer, NULL, &rendertargetView);
	deviceContext->OMSetRenderTargets(1, &rendertargetView, NULL);

	ZeroMemory(&viewPort, sizeof(D3D11_VIEWPORT));
	viewPort.TopLeftX = 0;
	viewPort.TopLeftY = 0;
	viewPort.Width = width;
	viewPort.Height = height;
	viewPort.MinDepth = 0.0f;
	viewPort.MaxDepth = 1.0f;
	deviceContext->RSSetViewports(1, &viewPort);
}

void DXApp::InitializeScene()
{
	triangle.SetPos(XMFLOAT2(-0.5f, 0.0f), XMFLOAT2(0.5f, 0.0f), XMFLOAT2(0.0f, 0.5f));
}

void DXApp::Render()
{
	float bgColor[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	deviceContext->ClearRenderTargetView(rendertargetView, bgColor);
	swapChain->Present(1, NULL);
}
