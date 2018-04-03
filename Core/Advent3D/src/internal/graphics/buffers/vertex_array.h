#pragma once

//buffer
#include "buffer.h"

//index buffer
#include "index_buffer.h"

namespace advent { namespace graphics {

	class VertexArray
	{

	private:

		GLuint m_ID;

	public:

		VertexArray();

		void bind() const;

		void unbind() const;

		void addBuffer(Buffer* buffer, GLuint index);

	};

} }