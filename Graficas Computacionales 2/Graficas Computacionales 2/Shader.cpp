#include "stdafx.h"
#include "Shader.h"

CShader::CShader()
{
	m_Shader = nullptr;
}

CShader::~CShader()
{
	Clear();
}

HRESULT CShader::CompileShader(char* entry, char* shaderModel)
{
	HRESULT hr = D3DCompileFromFile(L"../Debug/Shader.hlsl", NULL, NULL, entry, shaderModel, D3D10_SHADER_ENABLE_STRICTNESS, 0, &m_Shader, NULL);
	return hr;
}

void CShader::Clear()
{
	if (m_Shader)
		m_Shader->Release();
}

ID3DBlob* CShader::GetBLOB()
{
	return m_Shader;
}

/////////////////////////////////////////////////////////////

CVertexShader::CVertexShader()
{
	CShader::CShader();
	m_VertexShader = nullptr;
}

CVertexShader::~CVertexShader()
{
	CVertexShader::Clear();
}

HRESULT CVertexShader::CreateShader(ID3D11Device* device, char* entry, char* shaderModel)
{
	HRESULT hr = CompileShader(entry, shaderModel);
	if (FAILED(hr))
		return hr;
	device->CreateVertexShader(GetBLOB()->GetBufferPointer(), GetBLOB()->GetBufferSize(), NULL, &m_VertexShader);
	if (FAILED(hr))
		GetBLOB()->Release();
	return hr;
}

void CVertexShader::Clear()
{
	CShader::Clear();
	if (m_VertexShader)
		m_VertexShader->Release();
}

ID3D11VertexShader* CVertexShader::GetShader()
{
	return m_VertexShader;
}

/////////////////////////////////////////////////////////////

CPixelShader::CPixelShader()
{
	CShader::CShader();
	m_PixelShader = nullptr;
}

CPixelShader::~CPixelShader()
{
	CPixelShader::Clear();
}

HRESULT CPixelShader::CreateShader(ID3D11Device* device, char* entry, char* shaderModel)
{
	HRESULT hr = CompileShader(entry, shaderModel);
	if (FAILED(hr))
		return hr;
	device->CreatePixelShader(GetBLOB()->GetBufferPointer(), GetBLOB()->GetBufferSize(), NULL, &m_PixelShader);
	if (FAILED(hr))
		GetBLOB()->Release();
	return hr;
}

void CPixelShader::Clear()
{
	CShader::Clear();
	if (m_PixelShader)
		m_PixelShader->Release();
}

ID3D11PixelShader* CPixelShader::GetShader()
{
	return m_PixelShader;
}