#pragma once

#include <d3d11.h>

class CTexture2D
{
private:
	ID3D11Texture2D* m_Texture;
public:
	CTexture2D();
	~CTexture2D();
	void Clear();
	ID3D11Texture2D* GetTexture();
	ID3D11Texture2D** GetTexture2D();
};

class CDepthStencil final : public CTexture2D
{
private:
	D3D11_TEXTURE2D_DESC m_Desc;

public:
	CDepthStencil(UINT width, UINT height);
	~CDepthStencil();
	void Clear();
	HRESULT CreateDepthStencil(ID3D11Device* device);
};