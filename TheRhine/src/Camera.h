#pragma once
#include "rpch.h"

using namespace DirectX;

namespace Rhine
{
	class Camera
	{
	public:
		Camera();
		~Camera();

		XMVECTOR worldUp = { 0.0f, 1.0f, 0.0f };
		XMVECTOR worldRight = { 1.0f, 0.0f, 0.0f };
		XMVECTOR worldForward = { 0.0f, 0.0f, 1.0f };

		XMMATRIX world, view, projection;

		XMMATRIX GetWorld() const;
		XMMATRIX GetView() const;
		XMMATRIX GetProjection();

		float FoV = XMConvertToDegrees(90.0f);
		float aspectRatio = 1920 / 1080;
		float nearZ = 0.1f;
		float farZ = 10.0f;
	};
}

