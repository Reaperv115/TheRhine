#pragma once
#include <iostream>
#include <d3d11.h>
#include <DirectXMath.h>
#include <d3dcompiler.h>
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "DirectXTK.lib")
#pragma comment (lib, "D3DCompiler.lib")

#include <wrl/client.h>

#include "../Utilities/ErrorLogger.h"

using namespace DirectX;

namespace Rhine
{
	class PixelShader
	{
	public:
		PixelShader();
		~PixelShader();

		bool Initialize(ID3D11Device* device, std::wstring shaderPath);
		ID3D11PixelShader* GetShader();
		ID3D10Blob* GetBuffer();
	private:
		Microsoft::WRL::ComPtr<ID3D11PixelShader> shader;
		Microsoft::WRL::ComPtr<ID3D10Blob> shaderBuffer;
	};
}

