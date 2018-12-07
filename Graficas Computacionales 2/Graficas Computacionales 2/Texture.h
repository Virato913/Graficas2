#pragma once

#include <string>
#include <windows.h>

#include "assimp/types.h"

class Texture
{
private:
	WORD m_id;
	std::string m_type;
	aiString m_path;
public:
	Texture();
	~Texture();
	void setId(WORD id);
	void setType(std::string type);
	void setPath(aiString path);
	WORD getId();
	std::string getType();
	aiString getPath();
};
