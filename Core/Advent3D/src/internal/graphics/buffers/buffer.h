#pragma once

#include <GL\gl3w.h>

namespace advent { namespace graphics {

	class Buffer
	{

	private:
	
		GLuint m_ID;
		GLuint m_ComponentCount;

	public:

		Buffer(GLfloat* data, GLsizei count, GLuint componentCount, GLenum usage = GL_STATIC_DRAW);

		void bind() const;

		inline GLuint getComponentCount() const { return m_ComponentCount; }

	};


} }