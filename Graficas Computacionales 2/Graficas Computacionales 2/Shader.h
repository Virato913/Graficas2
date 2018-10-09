#pragma once

#include <d3d11.h>
#include <d3dcompiler.h>

class CShader
{
private:
	ID3DBlob* m_Shader = nullptr;

public:
	CShader();
	~CShader();
	HRESULT CompileShader(char* entry, char* shaderModel);
	void Clear();
	ID3DBlob* GetBLOB();
};

class CVertexShader final : public CShader
{
private:
	ID3D11VertexShader* m_VertexShader = nullptr;

public:
	CVertexShader();
	~CVertexShader();
	HRESULT CreateShader(ID3D11Device* device, char* entry, char* shaderModel = "vs_4_0");
	void Clear();
	ID3D11VertexShader* GetShader();
};

class CPixelShader final : public CShader
{
private:
	ID3D11PixelShader* m_PixelShader = nullptr;

public:
	CPixelShader();
	~CPixelShader();
	HRESULT CreateShader(ID3D11Device* device, char* entry, char* shaderModel = "ps_4_0");
	void Clear();
	ID3D11PixelShader* GetShader();
};