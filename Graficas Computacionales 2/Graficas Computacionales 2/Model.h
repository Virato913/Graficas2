#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"

class Model
{
private:
	std::vector<Mesh> m_meshes;
	std::string m_directory;
	std::vector<Texture> m_textures;

public:
	Model(const char* path);
	~Model();
	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	WORD textureFromFile(const char* path, std::string directory);
};

