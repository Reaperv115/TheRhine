#include "DXApp.h"

namespace Rhine
{
	D3D11_INPUT_ELEMENT_DESC triangleLayout[] =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
	};
	UINT numofElements = ARRAYSIZE(triangleLayout);
	

	DXApp::DXApp()
	{}

	DXApp::DXApp(HINSTANCE hInst)
	{
		mAppInst = hInst;
		InitMainWindow();

	}

	DXApp::~DXApp()
	{
		swapChain->Release();
		device->Release();
		deviceContext->Release();
		rendertargetView->Release();

	}

	HINSTANCE DXApp::AppInst() const
	{
		return mAppInst;
	}

	HWND DXApp::GetMainWnd() const
	{
		return mMainWnd;
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
		viewPort.MaxDepth = 1.0f;
		deviceContext->RSSetViewports(1, &viewPort);
	}

	void DXApp::InitializeScene()
	{
		device->CreateInputLayout(triangleLayout, numofElements, TriangleVS, sizeof(TriangleVS), &itriangleLayout);
		device->CreateVertexShader(TriangleVS, sizeof(TriangleVS), NULL, &triangleVS);
		device->CreatePixelShader(TrianglePS, sizeof(TrianglePS), NULL, &trianglePS);
	}

	void DXApp::Render()
	{
		float bgColor[] = { 1.0f, 0.0f, 0.0f, 1.0f };
		deviceContext->ClearRenderTargetView(rendertargetView, bgColor);
		deviceContext->IASetInputLayout(itriangleLayout);
		swapChain->Present(1, NULL);
	}

	bool DXApp::InitMainWindow()
	{
		RegisterWindow();
		mMainWnd = CreateWindowEx(0, windowclassName.c_str(), windowName.c_str(), style, 1000, 300, width, height, NULL, NULL, mAppInst, nullptr);
		ShowWindow(mMainWnd, SW_SHOW);
		SetForegroundWindow(mMainWnd);
		SetFocus(mMainWnd);
		InitializeDirectX();
		return true;
	}

	void DXApp::CalculateFrameStats()
	{
		static int frameCnt = 0;
		static float timeElapsed = 0.0f;

		frameCnt++;

		if ((gametimer.TotalTime() - timeElapsed) >= 1.0f)
		{
			float fps = (float)frameCnt;
			float mspf = 1000.0f / fps;

			std::wostringstream ss;
			ss.precision(6);
			ss << mMwndCaption << L"   "
				<< L"FPS: " << fps << L"  "
				<< L"Frame Time: " << mspf << L"  (ms)";
			SetWindowText(mMainWnd, ss.str().c_str());

			frameCnt = 0;
			timeElapsed += 1.0f;
		}
	}

	void DXApp::RegisterWindow()
	{
		WNDCLASSEX wc;
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = DefWindowProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = mAppInst;
		wc.hIcon = NULL;
		wc.hIconSm = NULL;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = NULL;
		wc.lpszMenuName = windowName.c_str();
		wc.lpszClassName = windowclassName.c_str();
		wc.cbSize = sizeof(WNDCLASSEX);
		RegisterClassEx(&wc);
	}

	int DXApp::Run()
	{
		MSG msg = { 0 };
		gametimer.Reset();
		ZeroMemory(&msg, sizeof(msg));
		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				gametimer.Tick();
				if (!mAppPaused)
				{
					CalculateFrameStats();
					DrawScene();
				}
				else
				{
					Sleep(100);
				}
			}
		}

		return (int)msg.wParam;
	}

	void DXApp::Init()
	{
		InitMainWindow();
	}

	bool DXApp::OnResize()
	{
		return false;
	}

	LRESULT DXApp::MsgProch(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		return LRESULT();
	}
}
