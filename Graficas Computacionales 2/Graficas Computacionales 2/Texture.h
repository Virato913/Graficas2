#pragma once

#include <string>
#include <windows.h>
#include <d3d11.h>
#include <iostream>
#include <fstream>

#include "assimp/types.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class Texture
{
private:
	WORD m_id;
	std::string m_type;
	aiString m_path;
	ID3D11Texture2D* m_texture;
	ID3D11ShaderResourceView* m_shaderResource;
	ID3D11SamplerState* m_samplerState;

public:
	Texture();
	~Texture();
	void setId(WORD id);
	void setType(std::string type);
	void setPath(aiString path);
	WORD getId();
	std::string getType();
	aiString getPath();
	void LoadFromFile(ID3D11Device* device, ID3D11DeviceContext* context);
};
