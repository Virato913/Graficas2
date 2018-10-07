#pragma once

#include "windows.h"
#include "Device.h"
#include "DeviceContext.h"
#include "RenderTargetView.h"
#include "Texture2D.h"
#include "Viewport.h"

class CGraphicsAPI
{
private:
	CDevice* m_Device;
	CDeviceContext* m_DeviceContext;
	CRenderTargetView* m_RenderTargetView;
	CSwapChain* m_SwapChain;
public:
	CGraphicsAPI();
	~CGraphicsAPI();
	HRESULT Init(HWND hWnd);
	void Render();
	void Clear();
};

