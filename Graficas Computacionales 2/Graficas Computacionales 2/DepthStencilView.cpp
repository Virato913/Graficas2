#include "stdafx.h"
#include "DepthStencilView.h"

CDepthStencilView::CDepthStencilView()
{
	m_DepthStencilView = nullptr;
}

CDepthStencilView::~CDepthStencilView()
{
	Clear();
}

HRESULT CDepthStencilView::CreateDepthStencilView(ID3D11Device* device, ID3D11Texture2D* depthStencil)
{
	D3D11_DEPTH_STENCIL_VIEW_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	desc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	desc.Texture2D.MipSlice = 0;
	return device->CreateDepthStencilView(depthStencil, &desc, &m_DepthStencilView);
}

void CDepthStencilView::Clear()
{
	if (m_DepthStencilView)
		m_DepthStencilView->Release();
}

ID3D11DepthStencilView* CDepthStencilView::GetDSV()
{
	return m_DepthStencilView;
}