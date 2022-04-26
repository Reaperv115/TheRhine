#include "rpch.h"
#include "Camera.h"

namespace Rhine
{
	XMMATRIX Camera::GetWorld() const
	{
		return XMMatrixIdentity();
	}

	XMMATRIX Camera::GetView() const
	{
		return XMMatrixPerspectiveFovLH(FoV, aspectRatio, nearZ, farZ);
	}

	XMMATRIX Camera::GetProjection()
	{
		return XMMATRIX();
	}

}