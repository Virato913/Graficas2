#pragma once

#include <d3d11.h>

class CRenderTargetView
{
private:
	ID3D11RenderTargetView* m_RenderTargetView;
public:
	CRenderTargetView();
	~CRenderTargetView();
	void Clear();
	ID3D11RenderTargetView* GetRenderTargetView();
	ID3D11RenderTargetView** GetRTV();
};

