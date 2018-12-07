#pragma once

#include <vector>

#include "GraphicsBuffer.h"
#include "MyMath.h"
#include "Texture.h"

class Mesh
{
private:
	std::vector<XVECTOR3> m_position;
	std::vector<XVECTOR3> m_normal;
	std::vector<XVECTOR2> m_texCoords;
	std::vector<WORD> m_indices;
	std::vector <Texture> m_textures;

public:
	Mesh(vector<XVECTOR3> position, vector<XVECTOR3> normal, vector<XVECTOR2> texCoords, vector<WORD> indices, vector<Texture> textures);
	~Mesh();
	void setUpMesh(CVertexBuffer<XVECTOR3>* vertices, CIndexBuffer<WORD>* indices);
};

