#include "Model.h"



Model::Model(const char* path)
{
	loadModel(path);
}

Model::~Model()
{
}

void Model::loadModel(std::string path)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate);
	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
		return;
	}
	m_directory = path.substr(0, path.find_last_of('/'));
	processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
	for (WORD i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		m_meshes.push_back(processMesh(mesh, scene));
	}
	for (WORD i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	vector<Vertex> vertices;
	vector<WORD> indices;
	vector<Texture> textures;

	for (WORD i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;

		XVECTOR3 position(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
		XVECTOR3 normal(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);
		if (mesh->mTextureCoords[0])
		{
			XVECTOR2 texCoords(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
			vertex.m_position = position;
			vertex.m_normal = normal;
			vertex.m_texCoords = texCoords;
		}
		else
		{
			XVECTOR2 texCoords(0.0f, 0.0f);
			vertex.m_position = position;
			vertex.m_normal = normal;
			vertex.m_texCoords = texCoords;
		}
		vertices.push_back(vertex);
	}
	
	for (WORD i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (WORD j = 0; j < face.mNumIndices; j++)
		{
			indices.push_back(face.mIndices[j]);
		}
	}

	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
		vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
		vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	}

	return Mesh(vertices, indices, textures);
}

vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
{
	vector<Texture> textures;
	for (WORD i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		bool skip = false;
		for (WORD j = 0; j < m_textures.size(); j++)
		{
			if (m_textures[j].getPath() == str)
			{
				textures.push_back(m_textures[j]);
				skip = true;
				break;
			}
		}
		if (!skip)
		{
			Texture texture;
			texture.setId(textureFromFile(str.C_Str(), m_directory));
			texture.setType(typeName);
			texture.setPath(str);
			textures.push_back(texture);
			m_textures.push_back(texture);
		}
	}
	return textures;
}

WORD Model::textureFromFile(const char* path, std::string directory)
{
	std::string filename = std::string(path);
	filename = directory + '/' + filename;
	WORD textureId = -1;

	//int width, height;

	//unsigned char* image =

	return textureId;
}