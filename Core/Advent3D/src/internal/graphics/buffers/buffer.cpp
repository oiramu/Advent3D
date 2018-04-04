#include "buffer.h"

namespace advent { namespace graphics {

	Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount, GLenum usage)
		:m_ComponentCount(componentCount)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * count, data, usage);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Buffer::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}

	void Buffer::unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &m_ID);
	}

} }