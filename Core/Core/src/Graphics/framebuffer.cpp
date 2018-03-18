#include "framebuffer.h"

FrameBuffer::FrameBuffer(float width, float height)
	:m_Width(width),m_Height(height)
{
	//FRAMEBUFFER//

	//generate the framebuffer
	glGenFramebuffers(1, &m_ID);
	
	//bind it
	glBindFramebuffer(GL_FRAMEBUFFER, m_ID);

	//generate the texture
	glGenTextures(1, &m_Texture);
	
	//bind the texture
	glBindTexture(GL_TEXTURE_2D, m_Texture);

	//setup the texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Texture, 0);

	//RENDERBUFFER//
	unsigned int rbo;
	
	//generate the renderbuffer
	glGenRenderbuffers(1, &rbo);
	
	//bind it
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	
	//set it up
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, m_Width, m_Height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
																								 
	//check if the framebuffer is complete
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cout << "Framebuffer with id '" << m_ID << "' is not complete." << std::endl;
	}

	//unbind it
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

//activate the framebuffer//
void FrameBuffer::Bind() const
{
	//bind it
	glBindFramebuffer(GL_FRAMEBUFFER, m_ID);
}

//get the texture//
unsigned int FrameBuffer::GetTexture()
{
	return m_Texture;
}

//get the width//
float FrameBuffer::GetWidth()
{
	return m_Width;
}

//get the height//
float FrameBuffer::GetHeight()
{
	return m_Height;
}

//get the ratio//
float FrameBuffer::GetRatio()
{
	return m_Width / m_Height;
}