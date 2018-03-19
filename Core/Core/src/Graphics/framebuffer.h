#pragma once

//opengl
#include <GL\gl3w.h>

//STL
#include <iostream>

class FrameBuffer
{
public:

	FrameBuffer(float width, float height);

	void Bind() const;

	unsigned int GetTexture();

	float GetWidth();

	float GetHeight();

	float GetRatio();

private:

	unsigned int m_ID;

	unsigned int m_Texture;

	float m_Width;
	float m_Height;

};