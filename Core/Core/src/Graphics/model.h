#pragma once

#include "mesh.h"

#include <ASSIMP\Importer.hpp>
#include <ASSIMP\scene.h>
#include <ASSIMP\postprocess.h>

#include <STB\stb_image.h>

class Model
{
public:

	Model(const std::string& path);

	void Draw(Shader& shader);

private:

	std::vector<Texture> m_TexturesLoaded;
	std::vector<Mesh> m_Meshes;
	std::string directory;

	bool Load(const std::string& path);
	void ProcessNode(aiNode *node, const aiScene *scene);
	Mesh ProcessMesh(aiMesh *mesh, const aiScene *scene);
	std::vector<Texture> LoadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);

};