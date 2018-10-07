#include "stdafx.h"
#include "GraphicsAPI.h"

CGraphicsAPI::CGraphicsAPI()
{
	m_Device = new CDevice();
	m_DeviceContext = new CDeviceContext();
	m_RenderTargetView = new CRenderTargetView();
	m_SwapChain = new CSwapChain();
}

CGraphicsAPI::~CGraphicsAPI()
{
	Clear();
}

HRESULT CGraphicsAPI::Init(HWND hWnd)
{
	HRESULT hr = S_OK;

	RECT rc;
	GetClientRect(hWnd, &rc);
	UINT width = rc.right - rc.left;
	UINT height = rc.bottom - rc.top;

	hr = m_Device->Init(m_DeviceContext, m_SwapChain, hWnd, width, height);
	if (FAILED(hr))
		return hr;

	hr = m_Device->CreateBackBuffer(m_RenderTargetView, m_SwapChain);
	if (FAILED(hr))
		return hr;

	m_DeviceContext->SetRTV(m_RenderTargetView);

	CViewport* vp = new CViewport();
	vp->Create(width, height);

	m_DeviceContext->SetVP(vp);

	return hr;
}

void CGraphicsAPI::Render()
{
	m_DeviceContext->Render(m_RenderTargetView);
	m_SwapChain->Render();
}

void CGraphicsAPI::Clear()
{
	m_DeviceContext->ClearState();
	m_RenderTargetView->Clear();
	m_SwapChain->Clear();
	m_DeviceContext->Clear();
	m_Device->Clear();
}