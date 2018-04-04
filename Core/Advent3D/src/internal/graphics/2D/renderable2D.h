#pragma once

//vertex array and buffers
#include "internal\graphics\buffers\buffer.h"
#include "internal\graphics\buffers\index_buffer.h"
#include "internal\graphics\buffers\vertex_array.h"

#include <maths\linear_algebra.h>

namespace advent { namespace graphics {

	//VertexData holds all the basic information about each vertex
	struct VertexData
	{
		maths::vec3 vertex;
		maths::vec4 color;
	};

	class Renderable2D
	{
		protected:

			maths::vec3 m_Position;
			maths::vec2 m_Size;
			maths::vec4 m_Color;

		public:

			Renderable2D(const maths::vec3& position, const maths::vec2& size, const maths::vec4& color);
			
			virtual ~Renderable2D();
			
			inline const maths::vec3& getPosition() const { return m_Position; }
			inline const maths::vec2& getSize() const { return m_Size; }
			inline const maths::vec4& getColor() const { return m_Color; }

	};

} }

