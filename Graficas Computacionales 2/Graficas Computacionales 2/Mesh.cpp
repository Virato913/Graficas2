#include "Mesh.h"



Mesh::Mesh(vector<XVECTOR3> position, vector<XVECTOR3> normal, vector<XVECTOR2> texCoords, vector<WORD> indices, vector<Texture> textures)
{
	m_position = position;
	m_normal = normal;
	m_texCoords = texCoords;
	m_indices = indices;
	m_textures = textures;
}

Mesh::~Mesh()
{
	m_position.clear();
	m_normal.clear();
	m_texCoords.clear();
	m_indices.clear();
	m_textures.clear();
}

void Mesh::setUpMesh(CVertexBuffer<XVECTOR3>* vertices, CIndexBuffer<WORD>* indices)
{
	//vertices->add(m_vertices);
	indices->add(m_indices);
}
