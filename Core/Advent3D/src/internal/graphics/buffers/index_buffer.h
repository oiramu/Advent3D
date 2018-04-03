#pragma once

#include <GL\gl3w.h>

namespace advent { namespace graphics {

	class IndexBuffer
	{

	private:

		GLuint m_ID;
		GLuint m_Count;

	public:

		IndexBuffer(GLushort* data, GLsizei count, GLenum usage = GL_STATIC_DRAW);

		void bind() const;

		void unbind() const;

		inline GLuint getCount() const { return m_Count; }

	};

} }