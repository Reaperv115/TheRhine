#include "DXApp.h"

namespace Rhine
{
	DXApp::DXApp()
	{}
	DXApp::DXApp(HINSTANCE hInst)
	{
		mAppInst = hInst;
		InitMainWindow();
	}

	DXApp::~DXApp()
	{

	}

	void DXApp::Run()
	{
		while (true)
		{

		}
	}
	int DXApp::RunMessageLoop()
	{
		MSG msg = { 0 };
		ZeroMemory(&msg, sizeof(msg));
		while (true)
		{

		}
		return 0;
	}
	void DXApp::InitializeDirectX()
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
		swapchainDesc.OutputWindow = mMainWnd;
		swapchainDesc.Windowed = true;
		swapchainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swapchainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
		D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, D3D11_CREATE_DEVICE_DEBUG, NULL, NULL, D3D11_SDK_VERSION, &swapchainDesc, &swapChain, &device, NULL, &deviceContext);

		swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);
		device->CreateRenderTargetView(backBuffer, NULL, &rendertargetView);
		backBuffer->Release();

		device->CreateRenderTargetView(backBuffer, NULL, &rendertargetView);
		deviceContext->OMSetRenderTargets(1, &rendertargetView, NULL);

		ZeroMemory(&viewPort, sizeof(D3D11_VIEWPORT));
		viewPort.TopLeftX = 0;
		viewPort.TopLeftY = 0;
		viewPort.Width = width;
		viewPort.Height = height;
		viewPort.MinDepth = 0.0f;
		viewPort.MaxDepth = 1.f;
		deviceContext->RSSetViewports(1, &viewPort);
	}

	void DXApp::RegisterWindow()
	{
		WNDCLASSEX wc;
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = DefWindowProc;
		wc.cbWndExtra = 0;
		wc.hInstance = mAppInst;
		wc.hIcon = NULL;
		wc.hIconSm = NULL;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = NULL;
		wc.lpszMenuName = windowmenuName.c_str();
		wc.lpszClassName = windowclassName.c_str();
		wc.cbSize = sizeof(WNDCLASSEX);
		RegisterClassEx(&wc);
	}

	void DXApp::InitMainWindow()
	{
		RegisterWindow();
		mMainWnd = CreateWindowEx(0, windowclassName.c_str(), windowmenuName.c_str(), style, 0, 0, width, height, NULL, NULL, mAppInst, nullptr);
		ShowWindow(mMainWnd, SW_SHOW);
		SetForegroundWindow(mMainWnd);
		SetFocus(mMainWnd);
		InitializeDirectX();
	}
	void DXApp::Render()
	{
		float bgcolor[] = { 1.0f, 0.0f, 0.0f, 1.0f };
		deviceContext->ClearRenderTargetView(rendertargetView, bgcolor);
		swapChain->Present(1, NULL);
	}
}