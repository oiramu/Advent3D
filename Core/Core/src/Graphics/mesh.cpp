#include "mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<Texture> textures, std::vector<unsigned int> indices)
	:m_Vertices(vertices), m_Textures(textures), m_Indices(indices)
{
	//generate the vertex array and buffers//
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_IBO);

	//bind the vertex array//
	glBindVertexArray(m_VAO);

	//setup the buffers

	//VBO//
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	//IBO//
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	//position//
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

	//normal//
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
	
	//texture coord//
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
	
	//tangent//
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
	
	//bitangent//
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));

	//unbind the vertex array//
	glBindVertexArray(0);
}

//(temporary) draws the mesh
void Mesh::Draw(Shader& shader)
{
	//number of textures
	unsigned int diffuseNr = 1;
	unsigned int specularNr = 1;
	unsigned int normalNr = 1;
	unsigned int heightNr = 1;

	//loop through the textures vector//
	for (unsigned int i = 0; i < m_Textures.size(); i++)
	{
		//active the appropriate texture before binding//
		glActiveTexture(GL_TEXTURE0 + i);
										  
		//retrieve the texture number//
		std::string number;
		std::string name = m_Textures[i].Type;

		if (name == "texture_diffuse")
			number = std::to_string(diffuseNr++);
		else if (name == "texture_specular")
			number = std::to_string(specularNr++);
		else if (name == "texture_normal")
			number = std::to_string(normalNr++);
		else if (name == "texture_height")
			number = std::to_string(heightNr++);

		//now set the sampler to the correct texture unit//
		shader.SetUniform<unsigned int>((name + number),i);

		//and finally bind the texture//
		glBindTexture(GL_TEXTURE_2D, m_Textures[i].ID);
	}

	//make the draw call//
	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	//unbind the texture//
	glActiveTexture(GL_TEXTURE0);
}