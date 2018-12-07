#include "Texture.h"



Texture::Texture()
{
	m_id = -1;
	m_type = "";
	m_path = "stone01.tga";
	m_texture = nullptr;
	m_samplerState = nullptr;
}

Texture::~Texture()
{

}

void Texture::setId(WORD id)
{
	m_id = id;
}

void Texture::setType(std::string type)
{
	m_type = type;
}

void Texture::setPath(aiString path)
{
	m_path = path;
}

WORD Texture::getId()
{
	return m_id;
}

std::string Texture::getType()
{
	return m_type;
}

aiString Texture::getPath()
{
	return m_path;
}

void Texture::LoadFromFile(ID3D11Device* device, ID3D11DeviceContext* context)
{
	int width, height, components;
	unsigned char* data = stbi_load(m_path.C_Str(), &width, &height, &components, 4);
	if (data)
	{
		HRESULT hr = S_OK;

		D3D11_TEXTURE2D_DESC descTexture;

		memset(&descTexture, 0, sizeof(descTexture));

		descTexture.Width = width;
		descTexture.Height = height;
		descTexture.MipLevels = 1;
		descTexture.ArraySize = 1;
		descTexture.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		descTexture.SampleDesc.Count = 1;
		descTexture.SampleDesc.Quality = 0;
		descTexture.Usage = D3D11_USAGE_DEFAULT;
		descTexture.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		descTexture.CPUAccessFlags = 0;
		descTexture.MiscFlags = 0;

		D3D11_SUBRESOURCE_DATA subresource;

		memset(&subresource, 0, sizeof(subresource));

		subresource.pSysMem = data;
		subresource.SysMemPitch = width * 4;

		hr = device->CreateTexture2D(&descTexture, &subresource, &m_texture);
		if (FAILED(hr))
		{
			throw std::exception("Failed to create texture");
			return;
		}
		stbi_image_free(data);

		hr = device->CreateShaderResourceView(m_texture, nullptr, &m_shaderResource);
		if (FAILED(hr))
		{
			throw std::exception("Failed to create shader resource view");
			return;
		}

		context->PSSetShaderResources(0, 1, &m_shaderResource);

		D3D11_SAMPLER_DESC sampDesc;
		
		memset(&sampDesc, 0, sizeof(sampDesc));
		sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
		sampDesc.MinLOD = 0;
		sampDesc.MaxLOD = D3D11_FLOAT32_MAX;
		
		hr = device->CreateSamplerState(&sampDesc, &m_samplerState);

		if (FAILED(hr))
		{
			throw std::exception("Failed to create sampler state");
			return;
		}
	}
	else
	{
		//throw std::exception("Texture failed to load");
		std::ifstream infile("BrickWall.jpg");
		std::string hola;
		if (infile.good())
		{
			hola = "good";
		}
		else
		{
			hola = "bad";
			std::ofstream ofile("Here");
		}
		stbi_image_free(data);
	}
}
