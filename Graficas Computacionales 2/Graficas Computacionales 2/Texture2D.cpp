#include "stdafx.h"
#include "Texture2D.h"

CTexture2D::CTexture2D()
{
	//m_Texture = nullptr;
}

CTexture2D::~CTexture2D()
{
	Clear();
}

void CTexture2D::Clear()
{
	if (m_Texture)
		m_Texture->Release();
}

ID3D11Texture2D* CTexture2D::GetTexture()
{
	return m_Texture;
}

ID3D11Texture2D** CTexture2D::GetTexture2D()
{
	return &m_Texture;
}

//////////////////////////////////////////////////

CDepthStencil::CDepthStencil(UINT width, UINT height)
{
	//CTexture2D::CTexture2D();
	ZeroMemory(&m_Desc, sizeof(m_Desc));
	m_Desc.Width = width;
	m_Desc.Height = height;
	m_Desc.MipLevels = 1;
	m_Desc.ArraySize = 1;
	m_Desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	m_Desc.SampleDesc.Count = 1;
	m_Desc.SampleDesc.Quality = 0;
	m_Desc.Usage = D3D11_USAGE_DEFAULT;
	m_Desc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	m_Desc.CPUAccessFlags = 0;
	m_Desc.MiscFlags = 0;
}

CDepthStencil::~CDepthStencil()
{
	Clear();
}

void CDepthStencil::Clear()
{
	CTexture2D::Clear();
	ZeroMemory(&m_Desc, sizeof(m_Desc));
}

HRESULT CDepthStencil::CreateDepthStencil(ID3D11Device* device)
{
	return device->CreateTexture2D(&m_Desc, NULL, GetTexture2D());
}