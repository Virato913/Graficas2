#pragma once

#include <vector>

#include "GraphicsBuffer.h"
#include "MyMath.h"
#include "Texture.h"

struct Vertex
{
	XVECTOR3 m_position;
	XVECTOR3 m_normal;
	XVECTOR2 m_texCoords;
};

class Mesh
{
private:
	std::vector<Vertex> m_vertices;
	std::vector<WORD> m_indices;
	std::vector <Texture> m_textures;

public:
	Mesh(vector<Vertex> vertices, vector<WORD> indices, vector<Texture> textures);
	~Mesh();
	void setUpMesh(CVertexBuffer<Vertex>* vertices, CIndexBuffer<WORD>* indices);
};

