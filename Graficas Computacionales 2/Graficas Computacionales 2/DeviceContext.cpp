#include "stdafx.h"
#include "DeviceContext.h"


CDeviceContext::CDeviceContext()
{
	m_DeviceContext = nullptr;
}

CDeviceContext::~CDeviceContext()
{
	Clear();
}

void CDeviceContext::SetRTV(CRenderTargetView* renderTargetView)
{
	m_DeviceContext->OMSetRenderTargets(1, renderTargetView->GetRTV(), NULL);
}

void CDeviceContext::SetVP(CViewport* viewport)
{
	m_DeviceContext->RSSetViewports(1, viewport->GetViewport());
}

void CDeviceContext::Render(CRenderTargetView* renderTargetView)
{
	float ClearColor[4] = { 0.4f,0.4f,1.0f,1.0f };
	m_DeviceContext->ClearRenderTargetView(renderTargetView->GetRenderTargetView(), ClearColor);
}

void CDeviceContext::Clear()
{
	if (m_DeviceContext)
		m_DeviceContext->Release();
}

void CDeviceContext::ClearState()
{
	if (m_DeviceContext)
		m_DeviceContext->ClearState();
}

ID3D11DeviceContext** CDeviceContext::GetDeviceContext()
{
	return &m_DeviceContext;
}