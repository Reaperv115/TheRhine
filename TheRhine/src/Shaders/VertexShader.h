#pragma once
using namespace DirectX;

namespace Rhine
{
	class VertexShader
	{
	public:
		VertexShader();
		~VertexShader();

		bool Initialize(ID3D11Device* device, std::wstring shaderPath);
		ID3D11VertexShader* GetShader();
		ID3D10Blob* GetBuffer();
	private:
		Microsoft::WRL::ComPtr<ID3D11VertexShader> shader;
		Microsoft::WRL::ComPtr<ID3D10Blob> shaderBuffer;
	};
}

