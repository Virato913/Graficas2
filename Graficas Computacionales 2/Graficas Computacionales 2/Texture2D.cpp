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