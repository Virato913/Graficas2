#pragma once

#include "DeviceContext.h"
#include "RenderTargetView.h"
#include "SwapChain.h"

#include <d3d11.h>
#include <vector>

using std::vector;

class CDevice
{
private:
	ID3D11Device* m_Device;
public:
	CDevice();
	~CDevice();
	HRESULT Init(CDeviceContext* deviceContext, CSwapChain* swapChain, HWND hWnd, UINT width, UINT height);
	HRESULT CreateBackBuffer(CRenderTargetView* renderTargetView, CSwapChain* swapChain);
	void Clear();
	ID3D11Device* GetDevice();
};

