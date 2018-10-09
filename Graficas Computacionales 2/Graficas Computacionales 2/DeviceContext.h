#pragma once

#include "RenderTargetView.h"
#include "Shader.h"
#include "Viewport.h"

#include <d3d11.h>

class CDeviceContext
{
private:
	ID3D11DeviceContext* m_DeviceContext;
public:
	CDeviceContext();
	~CDeviceContext();
	void SetRTV(CRenderTargetView* renderTargetView);
	void SetVP(CViewport* viewport);
	void Render(CRenderTargetView* renderTargetView);
	void Draw(CVertexShader* vertexShader, CPixelShader* pixelShader, ID3D11Buffer* constantBuffer);
	void Clear();
	void ClearState();
	ID3D11DeviceContext* GetDC();
	ID3D11DeviceContext** GetDeviceContext();
};

