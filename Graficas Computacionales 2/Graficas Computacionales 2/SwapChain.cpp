#include "stdafx.h"
#include "SwapChain.h"


CSwapChain::CSwapChain()
{
	//m_SwapChain = nullptr;
}

CSwapChain::~CSwapChain()
{
	Clear();
}

HRESULT CSwapChain::GetBuffer(CTexture2D* backBuffer)
{
	return m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)backBuffer->GetTexture2D());
}

void CSwapChain::Render()
{
	m_SwapChain->Present(0, 0);
}

void CSwapChain::Clear()
{
	if (m_SwapChain)
		m_SwapChain->Release();
}

IDXGISwapChain** CSwapChain::GetSwapChain()
{
	return &m_SwapChain;
}