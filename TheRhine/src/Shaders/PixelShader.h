#pragma once
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

