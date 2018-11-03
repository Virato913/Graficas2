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
	XVECTOR2 Tex;
};

//struct ConstantBuffer {
//	XMATRIX44 World;
//	XMATRIX44 View;
//	XMATRIX44 Projection;
//	XVECTOR3 LightDir[2];
//	XVECTOR3 LightColor[2];
//	XVECTOR3 OutputColor;
//};

struct ChangesEveryFrame
{
	XMATRIX44 mWorld;
	XVECTOR3 vMeshColor;
};

class CGraphicsAPI
{
private:
	CConstantBuffer<XMATRIX44>* m_NeverChanges;
	CConstantBuffer<XMATRIX44>* m_ChangeOnResize;
	CConstantBuffer<ChangesEveryFrame>* m_ChangesEveryFrame;
	CDepthStencil* m_DepthStencil;
	CDepthStencilView* m_DepthStencilView;
	CDevice* m_Device;
	CDeviceContext* m_DeviceContext;
	CIndexBuffer<WORD>* m_IndexBuffer;
	CInputLayout* m_InputLayout;
	CPixelShader* m_PixelShader;
	CPixelShader* m_PixelShaderSolid;
	CRenderTargetView* m_RenderTargetView;
	CSwapChain* m_SwapChain;
	CVertexBuffer<SimpleVertex>* m_VertexBuffer;
	CVertexShader* m_VertexShader;
	XMATRIX44 m_World;
	XMATRIX44 m_View;
	XMATRIX44 m_Projection;
	XVECTOR3 m_MeshColor;

public:
	CGraphicsAPI();
	~CGraphicsAPI();
	HRESULT Init(HWND hWnd);
	void Render();
	void Update();
	void Clear();
};

