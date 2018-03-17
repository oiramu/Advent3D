#pragma once

#include <GL\gl3w.h>
#include <iostream>

class FrameBuffer
{
private:

	unsigned int m_ID;
	unsigned int ColorTexture;
	float m_Width;
	float m_Height;

public:

	FrameBuffer(float width, float height);

	void bind() const;

	unsigned int GetTexture();

	float GetWidth();
	float GetHeight();
	float GetRatio();
};