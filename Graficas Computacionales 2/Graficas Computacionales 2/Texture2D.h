#pragma once

#include <d3d11.h>

enum class TYPE
{

};

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

