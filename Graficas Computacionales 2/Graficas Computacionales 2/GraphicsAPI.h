#pragma once

#include "windows.h"
#include "Device.h"
#include "DeviceContext.h"
#include "GraphicsBuffer.h"
#include "InputLayout.h"
#include "RenderTargetView.h"
#include "Shader.h"
#include "Texture2D.h"
#include "Viewport.h"

#include "MyMath.h"

struct SimpleVertex {
	XVECTOR3 Pos;
	XVECTOR3 Color;
};

struct ConstantBuffer {
	XMATRIX44 World;
	XMATRIX44 View;
	XMATRIX44 Projection;
};

class CGraphicsAPI
{
private:
	CConstantBuffer<ConstantBuffer>* m_ConstantBuffer;
	CDevice* m_Device;
	CDeviceContext* m_DeviceContext;
	CIndexBuffer<WORD>* m_IndexBuffer;
	CInputLayout* m_InputLayout;
	CPixelShader* m_PixelShader;
	CRenderTargetView* m_RenderTargetView;
	CSwapChain* m_SwapChain;
	CVertexBuffer<SimpleVertex>* m_VertexBuffer;
	CVertexShader* m_VertexShader;
	XMATRIX44 m_World;
	XMATRIX44 m_View;
	XMATRIX44 m_Projection;

	float t;
	DWORD dwTimeStart;

public:
	CGraphicsAPI();
	~CGraphicsAPI();
	HRESULT Init(HWND hWnd);
	void Render();
	void Update();
	void Clear();
};

