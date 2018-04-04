#pragma once

//opengl
#include <GL\gl3w.h>

namespace advent { namespace graphics {

	class IndexBuffer
	{

	private:

		GLuint m_ID;

	public:

		IndexBuffer(GLushort* data, GLsizei count, GLenum usage = GL_STATIC_DRAW);
		~IndexBuffer();

		void bind() const;

		void unbind() const;
	};

} }