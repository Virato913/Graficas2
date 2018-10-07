#pragma once

#include "Texture2D.h"

#include <d3d11.h>

class CSwapChain
{
public:
	IDXGISwapChain* m_SwapChain;
public:
	CSwapChain();
	~CSwapChain();
	HRESULT GetBuffer(CTexture2D* backBuffer);
	void Render();
	void Clear();
	IDXGISwapChain** GetSwapChain();
};

