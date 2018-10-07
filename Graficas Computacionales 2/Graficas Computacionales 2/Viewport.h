#pragma once

#include <d3d11.h>

class CViewport
{
private:
	D3D11_VIEWPORT m_Viewport;
public:
	CViewport();
	~CViewport();
	void Create(UINT width, UINT height);
	const D3D11_VIEWPORT* GetViewport();
};

