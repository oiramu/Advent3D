#pragma once

#include "internal\graphics\buffers\buffer.h"
#include "internal\graphics\buffers\index_buffer.h"
#include "internal\graphics\buffers\vertex_array.h"

#include "internal\graphics\shader.h"

#include "maths\maths.h"

namespace advent { namespace graphics {

	class Renderable2D
	{
		protected:
		
			maths::vec3 m_Position;
			maths::vec2 m_Size;
			maths::vec4 m_Color;

			Shader& m_Shader;

			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;

		public:

			Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color, Shader& shader);
			
			virtual ~Renderable2D();

			inline const Shader& getShader() const { return m_Shader; }
			inline const VertexArray* getVertexArray() const { return m_VertexArray; }
			inline const IndexBuffer* getIndexBuffer() const { return m_IndexBuffer; }
			
			inline const maths::vec3& getPosition() const { return m_Position; }
			inline const maths::vec2& getSize() const { return m_Size; }
			inline const maths::vec4& getColor() const { return m_Color; }

	};

} }

