#include "PixelShader.h"

namespace Rhine
{
	PixelShader::PixelShader()
	{

	}

	PixelShader::~PixelShader()
	{

	}

	bool PixelShader::Initialize(ID3D11Device* device, std::wstring shaderPath)
	{
		HRESULT hr = D3DReadFileToBlob(shaderPath.c_str(), shaderBuffer.GetAddressOf());
		if (FAILED(hr))
		{
			std::wstring errorMsg = L"Failed to load shader: ";
			errorMsg += shaderPath;
			ErrorLogger::LogError(hr, errorMsg);
			return false;
		}
		hr = device->CreatePixelShader(shaderBuffer.Get()->GetBufferPointer(), shaderBuffer.Get()->GetBufferSize(), NULL, shader.GetAddressOf());
		if (FAILED(hr))
		{
			std::wstring errormsg = L"Failed to create vertex shader: ";
			errormsg += shaderPath;
			ErrorLogger::LogError(hr, errormsg);
			return false;
		}
		return true;
	}

	ID3D11PixelShader* PixelShader::GetShader()
	{
		return shader.Get();
	}
	ID3D10Blob* PixelShader::GetBuffer()
	{
		return shaderBuffer.Get();
	}
}