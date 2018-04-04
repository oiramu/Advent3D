#pragma once

#include <maths\linear_algebra.h>

namespace advent { namespace graphics {

	//VertexData holds all the basic information about each vertex
	//it is used by the batch renderer to structure the buffer
	struct VertexData
	{
		maths::vec3 vertex;
		maths::vec4 color;
	};

	//it acts as a base class for sprites.
	class Renderable2D
	{
		protected:

			//components
			maths::vec3 m_Position;
			maths::vec2 m_Size;
			maths::vec4 m_Color;

		public:

			//constructor
			Renderable2D(const maths::vec3& position = maths::vec3(0,0,0), const maths::vec2& size = maths::vec2(1, 1), const maths::vec4& color = maths::vec4(1.0f, 1.0f, 1.0f, 1.0f));
			
			//simple getters
			inline const maths::vec3& getPosition() const { return m_Position; }
			inline const maths::vec2& getSize() const { return m_Size; }
			inline const maths::vec4& getColor() const { return m_Color; }

	};

} }

