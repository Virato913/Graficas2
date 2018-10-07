#include "stdafx.h"
#include "Viewport.h"

CViewport::CViewport()
{

}

CViewport::~CViewport()
{

}

void CViewport::Create(UINT width, UINT height)
{
	m_Viewport.Width = (FLOAT)width;
	m_Viewport.Height = (FLOAT)height;
	m_Viewport.MinDepth = 0.0f;
	m_Viewport.MaxDepth = 1.0f;
	m_Viewport.TopLeftX = 0;
	m_Viewport.TopLeftY = 0;
}

const D3D11_VIEWPORT* CViewport::GetViewport()
{
	return &m_Viewport;
}