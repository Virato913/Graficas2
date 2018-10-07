#pragma once

#include "RenderTargetView.h"
#include "Viewport.h"

#include <d3d11.h>

class CDeviceContext
{
public:
	ID3D11DeviceContext* m_DeviceContext;
public:
	CDeviceContext();
	~CDeviceContext();
	void SetRTV(CRenderTargetView* renderTargetView);
	void SetVP(CViewport* viewport);
	void Render(CRenderTargetView* renderTargetView);
	void Clear();
	void ClearState();
	ID3D11DeviceContext** GetDeviceContext();
};

