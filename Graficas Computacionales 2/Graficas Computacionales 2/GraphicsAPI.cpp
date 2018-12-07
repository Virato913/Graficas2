#include "stdafx.h"
#include "GraphicsAPI.h"

CGraphicsAPI::CGraphicsAPI()
{
	m_NeverChanges = new CConstantBuffer<XMATRIX44>();
	m_ChangeOnResize = new CConstantBuffer<XMATRIX44>();
	m_ChangesEveryFrame = new CConstantBuffer<ChangesEveryFrame>();
	m_DepthStencilView = new CDepthStencilView();
	m_Device = new CDevice();
	m_DeviceContext = new CDeviceContext();
	m_IndexBuffer = new CIndexBuffer<WORD>();
	m_InputLayout = new CInputLayout();
	m_PixelShader = new CPixelShader();
	m_PixelShaderSolid = new CPixelShader();
	m_RenderTargetView = new CRenderTargetView();
	m_SwapChain = new CSwapChain();
	m_texture = new Texture();
	m_VertexBuffer = new CVertexBuffer<SimpleVertex>();
	m_VertexShader = new CVertexShader();
	m_MeshColor = XVECTOR3(0.7f, 0.7f, 0.7f, 1.0f);
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

	m_DepthStencil = new CDepthStencil(width, height);
	hr = m_DepthStencil->CreateDepthStencil(m_Device->GetDevice());
	if (FAILED(hr))
		return hr;

	hr = m_DepthStencilView->CreateDepthStencilView(m_Device->GetDevice(), m_DepthStencil->GetTexture());
	if (FAILED(hr))
		return hr;

	m_DeviceContext->SetRT(m_RenderTargetView, m_DepthStencilView);

	CViewport* vp = new CViewport();
	vp->Create(width, height);

	m_DeviceContext->SetVP(vp);

	hr = m_VertexShader->CreateShader(m_Device->GetDevice(), "VS");
	if (FAILED(hr))
		return hr;

	m_InputLayout->reserve(2);
	m_InputLayout->add("POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0);
	m_InputLayout->add("TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0);
	m_InputLayout->createInputLayout(m_Device->GetDevice(), m_VertexShader->GetBLOB()->GetBufferPointer(), m_VertexShader->GetBLOB()->GetBufferSize());
	m_InputLayout->setInputLayout(m_DeviceContext->GetDC());

	hr = m_PixelShader->CreateShader(m_Device->GetDevice(), "PS");
	if (FAILED(hr))
		return hr;

	m_VertexBuffer->reserve(8);
	SimpleVertex vertices[] =
	{
		{ XVECTOR3(-1.0f, 1.0f, -1.0f),	 XVECTOR2(0.0f, 0.0f) },
		{ XVECTOR3(1.0f, 1.0f, -1.0f),	 XVECTOR2(1.0f, 0.0f) },
		{ XVECTOR3(1.0f, 1.0f, 1.0f),	 XVECTOR2(1.0f, 1.0f) },
		{ XVECTOR3(-1.0f, 1.0f, 1.0f),	 XVECTOR2(0.0f, 1.0f) },

		{ XVECTOR3(-1.0f, -1.0f, -1.0f), XVECTOR2(0.0f, 0.0f) },
		{ XVECTOR3(1.0f, -1.0f, -1.0f),	 XVECTOR2(1.0f, 0.0f) },
		{ XVECTOR3(1.0f, -1.0f, 1.0f),	 XVECTOR2(1.0f, 1.0f) },
		{ XVECTOR3(-1.0f, -1.0f, 1.0f),	 XVECTOR2(0.0f, 1.0f) },

		{ XVECTOR3(-1.0f, -1.0f, 1.0f),	 XVECTOR2(0.0f, 0.0f) },
		{ XVECTOR3(-1.0f, -1.0f, -1.0f), XVECTOR2(1.0f, 0.0f) },
		{ XVECTOR3(-1.0f, 1.0f, -1.0f),	 XVECTOR2(1.0f, 1.0f) },
		{ XVECTOR3(-1.0f, 1.0f, 1.0f),	 XVECTOR2(0.0f, 1.0f) },

		{ XVECTOR3(1.0f, -1.0f, 1.0f),	 XVECTOR2(0.0f, 0.0f) },
		{ XVECTOR3(1.0f, -1.0f, -1.0f),	 XVECTOR2(1.0f, 0.0f) },
		{ XVECTOR3(1.0f, 1.0f, -1.0f),	 XVECTOR2(1.0f, 1.0f) },
		{ XVECTOR3(1.0f, 1.0f, 1.0f),	 XVECTOR2(0.0f, 1.0f) },

		{ XVECTOR3(-1.0f, -1.0f, -1.0f), XVECTOR2(0.0f, 0.0f) },
		{ XVECTOR3(1.0f, -1.0f, -1.0f),	 XVECTOR2(1.0f, 0.0f) },
		{ XVECTOR3(1.0f, 1.0f, -1.0f),	 XVECTOR2(1.0f, 1.0f) },
		{ XVECTOR3(-1.0f, 1.0f, -1.0f),	 XVECTOR2(0.0f, 1.0f) },

		{ XVECTOR3(-1.0f, -1.0f, 1.0f),	 XVECTOR2(0.0f, 0.0f) },
		{ XVECTOR3(1.0f, -1.0f, 1.0f),	 XVECTOR2(1.0f, 0.0f) },
		{ XVECTOR3(1.0f, 1.0f, 1.0f),	 XVECTOR2(1.0f, 1.0f) },
		{ XVECTOR3(-1.0f, 1.0f, 1.0f),	 XVECTOR2(0.0f, 1.0f) },
	};
	m_VertexBuffer->add(vertices, 24);
	m_VertexBuffer->createHardwareBuffer(m_Device->GetDevice());
	m_VertexBuffer->setHardwareBuffer(m_DeviceContext->GetDC(), sizeof(SimpleVertex), 0);

	m_IndexBuffer->reserve(36);
	WORD indices[] =
	{
		3,1,0,
		2,1,3,

		6,4,5,
		7,4,6,

		11,9,8,
		10,9,11,

		14,12,13,
		15,12,14,

		19,17,16,
		18,17,19,

		22,20,21,
		23,20,22
	};
	m_IndexBuffer->add(indices, 36);
	m_IndexBuffer->createHardwareBuffer(m_Device->GetDevice());
	m_IndexBuffer->setHardwareBuffer(m_DeviceContext->GetDC());

	m_DeviceContext->GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	m_NeverChanges->createHardwareBuffer(m_Device->GetDevice());
	m_ChangeOnResize->createHardwareBuffer(m_Device->GetDevice());
	m_ChangesEveryFrame->createHardwareBuffer(m_Device->GetDevice());

	//Here's where the texture would be loaded
	//And here's where the sampler would be created

	m_texture->LoadFromFile(m_Device->GetDevice(), m_DeviceContext->GetDC());

	XMatIdentity(m_World);

	XVECTOR3 Eye(0.0f, 4.0f, -10.0f, 0.0f);
	XVECTOR3 At(0.0f, 1.0f, 0.0f, 0.0f);
	XVECTOR3 Up(0.0f, 1.0f, 0.0f, 0.0f);
	XMatViewLookAtLH(m_View, Eye, At, Up);

	XMATRIX44 view;
	XMatTranspose(view, m_View);
	m_DeviceContext->GetDC()->UpdateSubresource(m_NeverChanges->GetBufferPointer(), 0, NULL, &view, 0, 0);

	XMatPerspectiveLH(m_Projection, xHALF_PI / 2.0f, width / (FLOAT)height, 0.01f, 100.0f);

	XMATRIX44 projection;
	XMatTranspose(projection, m_Projection);
	m_DeviceContext->GetDC()->UpdateSubresource(m_ChangeOnResize->GetBufferPointer(), 0, NULL, &projection, 0, 0);

	return hr;
}

//void CGraphicsAPI::Render()
//{
//	Update();
//
//	/*t += (float)xPI * 0.0125f;
//	XMatRotationYLH(m_World, t);*/
//
//	m_DeviceContext->Render(m_RenderTargetView, m_DepthStencilView);
//
//	/*ConstantBuffer cb;
//	XMatTranspose(cb.World, m_World);
//	XMatTranspose(cb.View, m_View);
//	XMatTranspose(cb.Projection, m_Projection);
//	m_DeviceContext->GetDC()->UpdateSubresource(m_ConstantBuffer->GetBufferPointer(), 0, NULL, &cb, 0, 0);*/
//
//	m_DeviceContext->Draw(m_VertexShader, m_PixelShader, m_ConstantBuffer->GetBufferPointer());
//	m_SwapChain->Render();
//}

void CGraphicsAPI::Render()
{
	static float t = 0.0f;
	static DWORD dwTimeStart = 0;
	DWORD dwTimeCur = GetTickCount();
	if (dwTimeStart == 0)
		dwTimeStart = dwTimeCur;
	t = (dwTimeCur - dwTimeStart) / 1000.0f;

	XMatRotationYLH(m_World, Deg2Rad(t/100.0));

	m_MeshColor.x = (sinf(t * 1.0f) + 1.0f) * 0.5f;
	m_MeshColor.y = (cosf(t * 3.0f) + 1.0f) * 0.5f;
	m_MeshColor.z = (sinf(t * 5.0f) + 1.0f) * 0.5f;

	float color[4] = { 0.0f,0.125f,0.3f,1.0f };
	m_DeviceContext->GetDC()->ClearRenderTargetView(m_RenderTargetView->GetRenderTargetView(), color);
	m_DeviceContext->GetDC()->ClearDepthStencilView(m_DepthStencilView->GetDSV(), D3D11_CLEAR_DEPTH, 1.0f, 0);

	ChangesEveryFrame cb;
	XMatTranspose(cb.mWorld, m_World);
	cb.vMeshColor = m_MeshColor;
	m_DeviceContext->GetDC()->UpdateSubresource(m_ChangesEveryFrame->GetBufferPointer(), 0, NULL, &cb, 0, 0);

	m_DeviceContext->GetDC()->VSSetShader(m_VertexShader->GetShader(), NULL, 0);
	m_DeviceContext->GetDC()->VSSetConstantBuffers(0, 1, m_NeverChanges->GetBuffer());
	m_DeviceContext->GetDC()->VSSetConstantBuffers(1, 1, m_ChangeOnResize->GetBuffer());
	m_DeviceContext->GetDC()->VSSetConstantBuffers(2, 1, m_ChangesEveryFrame->GetBuffer());
	m_DeviceContext->GetDC()->PSSetShader(m_PixelShader->GetShader(), NULL, 0);
	m_DeviceContext->GetDC()->PSSetConstantBuffers(2, 1, m_ChangesEveryFrame->GetBuffer());
	m_DeviceContext->GetDC()->DrawIndexed(36, 0, 0);

	m_SwapChain->Render();
}

void CGraphicsAPI::Update()
{
	static float t = 0.0f;
	static DWORD dwTimeStart = 0;
	DWORD dwTimeCur = GetTickCount();
	if (dwTimeStart == 0)
		dwTimeStart = dwTimeCur;
	t = (dwTimeCur - dwTimeStart) / 100000.0f;

	XMatRotationYLH(m_World, Deg2Rad(t));

	XVECTOR3 LightDirs[2] =
	{
		XVECTOR3(-0.577f, 0.577f, -0.577f, 1.0f),
		XVECTOR3(0.0f, 0.0f, -1.0f, 1.0f),
	};
	XVECTOR3 LightColors[2] =
	{
		XVECTOR3(0.5f, 0.5f, 0.5f, 1.0f),
		XVECTOR3(0.5f, 0.0f, 0.0f, 1.0f)
	};

	XMATRIX44 Rotate;
	XMatRotationYLH(Rotate, Deg2Rad(-2.0f*t));
	XVECTOR3 LightDir = LightDirs[1];
	XVecTransformLH(LightDirs[1], LightDir, Rotate);

	//ConstantBuffer cb1;
	//XMatTranspose(cb1.World, m_World);
	//XMatTranspose(cb1.View, m_View);
	//XMatTranspose(cb1.Projection, m_Projection);
	//cb1.LightDir[0] = LightDirs[0];
	//cb1.LightDir[1] = LightDirs[1];
	//cb1.LightColor[0] = LightColors[0];
	//cb1.LightColor[1] = LightColors[1];
	//cb1.OutputColor = XVECTOR3(0, 0, 0, 0);
	//m_DeviceContext->GetDC()->UpdateSubresource(m_ConstantBuffer->GetBufferPointer(), 0, NULL, &cb1, 0, 0);
}

void CGraphicsAPI::Clear()
{
	m_DeviceContext->ClearState();

	//m_ConstantBuffer->clear();
	m_VertexBuffer->clear();
	m_IndexBuffer->clear();
	m_InputLayout->clear();
	m_VertexShader->Clear();
	m_PixelShaderSolid->Clear();
	m_PixelShader->Clear();
	m_DepthStencil->Clear();
	m_DepthStencilView->Clear();
	m_RenderTargetView->Clear();
	m_SwapChain->Clear();
	m_DeviceContext->Clear();
	m_Device->Clear();
}