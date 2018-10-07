#include "stdafx.h"
#include "RenderTargetView.h"

CRenderTargetView::CRenderTargetView()
{
	m_RenderTargetView = nullptr;
}

CRenderTargetView::~CRenderTargetView()
{
	Clear();
}

void CRenderTargetView::Clear()
{
	if (m_RenderTargetView)
		m_RenderTargetView->Release();
}

ID3D11RenderTargetView* CRenderTargetView::GetRenderTargetView()
{
	return m_RenderTargetView;
}

ID3D11RenderTargetView** CRenderTargetView::GetRTV()
{
	return &m_RenderTargetView;
}