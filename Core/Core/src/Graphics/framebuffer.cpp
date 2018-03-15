#include "framebuffer.h"

FrameBuffer::FrameBuffer(float width, float height)
	:m_Width(width),m_Height(height)
{
	glGenFramebuffers(1, &m_ID);
	glBindFramebuffer(GL_FRAMEBUFFER, m_ID);

	// create a color attachment texture
	glGenTextures(1, &ColorTexture);
	glBindTexture(GL_TEXTURE_2D, ColorTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, ColorTexture, 0);

	unsigned int rbo;
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, m_Width, m_Height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
																								 
	//check if the framebuffer is complete
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cout << "Framebuffer with id '" << m_ID << "' is not complete." << std::endl;
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBuffer::bind() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_ID);
}

unsigned int FrameBuffer::GetTexture()
{
	return ColorTexture;
}

float FrameBuffer::GetWidth()
{
	return m_Width;
}

float FrameBuffer::GetHeight()
{
	return m_Height;
}

float FrameBuffer::GetRatio()
{
	return m_Width / m_Height;
}