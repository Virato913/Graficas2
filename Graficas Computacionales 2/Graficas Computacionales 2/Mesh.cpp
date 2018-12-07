#include "Mesh.h"



Mesh::Mesh(vector<Vertex> vertices, vector<WORD> indices, vector<Texture> textures)
{
	m_vertices = vertices;
	m_indices = indices;
	m_textures = textures;
}

Mesh::~Mesh()
{
	m_vertices.clear();
	m_indices.clear();
	m_textures.clear();
}

void Mesh::setUpMesh(CVertexBuffer<Vertex>* vertexBuffer, CIndexBuffer<WORD>* indexBuffer)
{
	vertexBuffer->add(m_vertices);
	indexBuffer->add(m_indices);
}
