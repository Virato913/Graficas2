#include "Texture.h"



Texture::Texture()
{
	m_id = -1;
	m_type = "";
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
