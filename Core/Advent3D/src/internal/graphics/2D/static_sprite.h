#pragma once

//renderable2D 
#include "renderable2D.h"

//shader
#include "internal\graphics\shader.h"

//TODO: replace buffers, vertex array with opengl stuff rather than classes

namespace advent { namespace graphics {

	class StaticSprite : public Renderable2D
	{
		private:
			
			Shader& m_Shader;

			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;

		public:

			StaticSprite(const maths::vec3& position, const maths::vec2& size, const maths::vec4& color, Shader& shader);
			~StaticSprite();

			inline const Shader& getShader() const { return m_Shader; }
			inline const VertexArray* getVertexArray() const { return m_VertexArray; }
			inline const IndexBuffer* getIndexBuffer() const { return m_IndexBuffer; }
	};

} }