#include "stdafx.h"
#include "GraphicsAPI.h"

CGraphicsAPI::CGraphicsAPI()
{
	m_ConstantBuffer = new CConstantBuffer<ConstantBuffer>();
	m_Device = new CDevice();
	m_DeviceContext = new CDeviceContext();
	m_IndexBuffer = new CIndexBuffer<WORD>();
	m_InputLayout = new CInputLayout();
	m_PixelShader = new CPixelShader();
	m_RenderTargetView = new CRenderTargetView();
	m_SwapChain = new CSwapChain();
	m_VertexBuffer = new CVertexBuffer<SimpleVertex>();
	m_VertexShader = new CVertexShader();
	t = 0;
	dwTimeStart = 0;
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

	hr = m_VertexShader->CreateShader(m_Device->GetDevice(), "VS");
	if (FAILED(hr))
		return hr;

	m_InputLayout->reserve(2);
	m_InputLayout->add("POSITION", (UINT)0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0);
	m_InputLayout->add("COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0);
	m_InputLayout->createInputLayout(m_Device->GetDevice(), m_VertexShader->GetBLOB()->GetBufferPointer(), m_VertexShader->GetBLOB()->GetBufferSize());
	m_InputLayout->setInputLayout(m_DeviceContext->GetDC());

	hr = m_PixelShader->CreateShader(m_Device->GetDevice(), "PS");
	if (FAILED(hr))
		return hr;

	m_VertexBuffer->reserve(8);
	SimpleVertex vertices[] =
	{
		{ XVECTOR3(-1.0f, 1.0f, -1.0f),	 XVECTOR3(0.0f, 0.0f, 1.0f, 1.0f) },
		{ XVECTOR3(1.0f, 1.0f, -1.0f),	 XVECTOR3(0.0f, 1.0f, 0.0f, 1.0f) },
		{ XVECTOR3(1.0f, 1.0f, 1.0f),	 XVECTOR3(0.0f, 1.0f, 1.0f, 1.0f) },
		{ XVECTOR3(-1.0f, 1.0f, 1.0f),	 XVECTOR3(1.0f, 0.0f, 0.0f, 1.0f) },
		{ XVECTOR3(-1.0f, -1.0f, -1.0f), XVECTOR3(1.0f, 0.0f, 1.0f, 1.0f) },
		{ XVECTOR3(1.0f, -1.0f, -1.0f),	 XVECTOR3(1.0f, 1.0f, 0.0f, 1.0f) },
		{ XVECTOR3(1.0f, -1.0f, 1.0f),	 XVECTOR3(1.0f, 1.0f, 1.0f, 1.0f) },
		{ XVECTOR3(-1.0f, -1.0f, 1.0f),	 XVECTOR3(0.0f, 0.0f, 0.0f, 1.0f) },
	};
	m_VertexBuffer->add(vertices,8);
	m_VertexBuffer->createHardwareBuffer(m_Device->GetDevice());
	m_VertexBuffer->setHardwareBuffer(m_DeviceContext->GetDC(), sizeof(SimpleVertex), 0);

	m_IndexBuffer->reserve(36);
	WORD indices[] =
	{
		3,1,0,
		2,1,3,

		0,5,4,
		1,5,0,

		3,4,7,
		0,4,3,

		1,6,5,
		2,6,1,

		2,7,6,
		3,7,2,

		6,4,5,
		7,4,6,
	};
	m_IndexBuffer->add(indices,36);
	m_IndexBuffer->createHardwareBuffer(m_Device->GetDevice());
	m_IndexBuffer->setHardwareBuffer(m_DeviceContext->GetDC());

	m_DeviceContext->GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	m_ConstantBuffer->createHardwareBuffer(m_Device->GetDevice());

	XMatIdentity(m_World);

	XVECTOR3 Eye(0.0f, 1.0f, -5.0f, 0.0f);
	XVECTOR3 At(0.0f, 1.0f, 0.0f, 0.0f);
	XVECTOR3 Up(0.0f, 1.0f, 0.0f, 0.0f);
	XMatViewLookAtLH(m_View, Eye, At, Up);

	XMatPerspectiveLH(m_Projection, xHALF_PI, width / (FLOAT)height, 0.01f, 100.0f);

	return hr;
}

void CGraphicsAPI::Render()
{
	//Update();

	t += (float)xPI * 0.0125f;
	XMatRotationYLH(m_World, t);

	m_DeviceContext->Render(m_RenderTargetView);

	ConstantBuffer cb;
	XMatTranspose(cb.World, m_World);
	XMatTranspose(cb.View, m_View);
	XMatTranspose(cb.Projection, m_Projection);
	m_DeviceContext->GetDC()->UpdateSubresource(m_ConstantBuffer->GetBufferPointer(), 0, NULL, &cb, 0, 0);

	m_DeviceContext->Draw(m_VertexShader, m_PixelShader, m_ConstantBuffer->GetBufferPointer());
	m_SwapChain->Render();
}

void CGraphicsAPI::Update()
{
	DWORD dwTimeCur = GetTickCount();
	if (dwTimeStart == 0)
		dwTimeStart = dwTimeCur;
	t = (dwTimeCur - dwTimeStart) / 1000.0f;
	XMatRotationYLH(m_World, t);
	ConstantBuffer cb;
	XMatTranspose(cb.World, m_World);
	XMatTranspose(cb.View, m_View);
	XMatTranspose(cb.Projection, m_Projection);
	m_DeviceContext->GetDC()->UpdateSubresource(m_ConstantBuffer->GetBufferPointer(), 0, NULL, &cb, 0, 0);
}

void CGraphicsAPI::Clear()
{
	m_DeviceContext->ClearState();

	m_ConstantBuffer->clear();
	m_VertexBuffer->clear();
	m_IndexBuffer->clear();
	m_InputLayout->clear();
	m_VertexShader->Clear();
	m_PixelShader->Clear();
	m_RenderTargetView->Clear();
	m_SwapChain->Clear();
	m_DeviceContext->Clear();
	m_Device->Clear();
}