#include "rpch.h"
#include "DXApp.h"

namespace Rhine
{
	struct Vertex
	{
		XMFLOAT4 position;
		XMFLOAT4 color;

		Vertex()
		{

		}
		Vertex(float x, float y, float z, float w, float r, float g, float b, float a)
		{
			position.x = x;
			position.y = y;
			position.z = z;
			position.w = w;
			color.x = r;
			color.y = g;
			color.z = b;
			color.w = a;
		}
	};
	

	DXApp::DXApp()
	{

	}
	DXApp::~DXApp()
	{

	}

	void DXApp::InitializeDirectX()
	{
		
		ZeroMemory(&swapchainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
		swapchainDesc.BufferCount = 1;
		swapchainDesc.BufferDesc.Width = width;
		swapchainDesc.BufferDesc.Height = height;
		swapchainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapchainDesc.BufferDesc.RefreshRate.Numerator = 60;
		swapchainDesc.BufferDesc.RefreshRate.Denominator = 1;
		swapchainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swapchainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		swapchainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapchainDesc.SampleDesc.Count = 1;
		swapchainDesc.SampleDesc.Quality = 0;
		swapchainDesc.Windowed = true;
		swapchainDesc.OutputWindow = windowhandle;
		swapchainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
		swapchainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		HRESULT factoryinstHR = CreateDXGIFactory(__uuidof(IDXGIFactory), (LPVOID*)&factoryInst);
		if (FAILED(factoryinstHR))
		{
			ErrorLogger::LogError(factoryinstHR, L"Failed to create factory instance");
		}
		HRESULT dHR = D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, D3D11_CREATE_DEVICE_DEBUG, NULL, NULL, D3D11_SDK_VERSION, &device, NULL, &deviceContext);
		if (FAILED(dHR))
		{
			ErrorLogger::LogError(dHR, L"Failed to create device");
		}
		HRESULT scHR = factoryInst->CreateSwapChain(device, &swapchainDesc, &swapChain);
		if (FAILED(scHR))
		{
			ErrorLogger::LogError(scHR, L"Failed to create swapchain");
		}
		//D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, D3D11_CREATE_DEVICE_DEBUG, NULL, NULL, D3D11_SDK_VERSION, &swapchainDesc, &swapChain, &device, NULL, &deviceContext);

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

	void DXApp::Render()
	{
		float bgcolor[] = { 1.0f, 0.0f, 0.0f, 1.0f };
		deviceContext->ClearRenderTargetView(rendertargetView, bgcolor);
		deviceContext->IASetInputLayout(ilayOut);
		stride = sizeof(Vertex);
		deviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
		deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
		deviceContext->VSSetShader(vShader.GetShader(), NULL, 0);
		deviceContext->PSSetShader(pShader.GetShader(), NULL, 0);
		deviceContext->Draw(3, 0);
		swapChain->Present(1, NULL);
	}

	void DXApp::InitializeScene()
	{
		Vertex triangle[3];
		triangle[0] = Vertex(0.0f, 0.5f, 0.0f, 1.0f,        1.0f, 0.0f, 0.0f, 1.0f);
		triangle[1] = Vertex(0.5f, -0.5f, 0.0f, 1.0f,       0.0f, 1.0f, 0.0f, 1.0f);
		triangle[2] = Vertex(-0.5f, -0.5f, 0.0f, 1.0f,      0.0f, 0.0f, 1.0f, 1.0f);

		vShader.Initialize(device, L"../bin/x64-Debug/TheRhine/TriangleVS.cso");
		pShader.Initialize(device, L"../bin/x64-Debug/TheRhine/TrianglePS.cso");

		D3D11_INPUT_ELEMENT_DESC layout[] =
		{
			{"POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		};
		UINT numofElements = ARRAYSIZE(layout);
		device->CreateInputLayout(layout, numofElements, vShader.GetBuffer()->GetBufferPointer(), vShader.GetBuffer()->GetBufferSize(), &ilayOut);

		ZeroMemory(&bufferDesc, sizeof(bufferDesc));
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.ByteWidth = sizeof(triangle);
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;
		bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		ZeroMemory(&subresource, sizeof(subresource));
		subresource.pSysMem = triangle;
		subresource.SysMemPitch = 0;
		subresource.SysMemSlicePitch = 0;
		HRESULT dHR = device->CreateBuffer(&bufferDesc, &subresource, &vertexBuffer);
		if (FAILED(dHR))
		{
			ErrorLogger::LogError(dHR, L"Failed to create vertex buffer");
		}
	}

	HWND DXApp::GetWindowHandle() const
	{
		return windowhandle;
	}
}