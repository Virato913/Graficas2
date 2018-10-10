#pragma once

#include <d3d11.h>

class CDepthStencilView
{
private:
	ID3D11DepthStencilView* m_DepthStencilView = nullptr;
public:
	CDepthStencilView();
	~CDepthStencilView();
	HRESULT CreateDepthStencilView(ID3D11Device* device, ID3D11Texture2D* depthStencil);
	void Clear();
	ID3D11DepthStencilView* GetDSV();
};

