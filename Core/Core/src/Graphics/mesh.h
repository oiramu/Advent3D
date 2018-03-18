#pragma once

//opengl
#include <GL\gl3w.h>

//maths
#include <GLM\vec2.hpp>
#include <GLM\vec3.hpp>

//STL
#include <vector>
#include <string>

//shader
#include "shader.h"

//vertex//
struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
	glm::vec3 Tangent;	
	glm::vec3 Bitangent;
};

//texture//
struct Texture
{
	unsigned int ID;
	std::string Type;
	std::string Path;
};

//base mesh class//
class Mesh
{

public:

	//TODO: draw mesh with model class
	std::vector<Vertex> m_Vertices;
	std::vector<Texture> m_Textures;
	std::vector<unsigned int> m_Indices;

	Mesh(std::vector<Vertex> vertices, std::vector<Texture> textures, std::vector<unsigned int> indices);

	//(temporary) draws the mesh
	void Draw(Shader& shader);

	//get the VAO//
	unsigned int GetVAO() const { return m_VAO; }
	
	//get the IBO//
	unsigned int GetIBO() const { return m_IBO; }

private:
	
	//vertex array and buffers//
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;

};