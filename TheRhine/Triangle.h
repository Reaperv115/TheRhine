#pragma once
#include <DirectXMath.h>
using namespace DirectX;
class Triangle
{
	XMFLOAT3 pos[3];
	public:
		void SetPos(XMFLOAT2 position1, XMFLOAT2 position2, XMFLOAT2 position3);
};

