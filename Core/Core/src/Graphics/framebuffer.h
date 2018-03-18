#pragma once

//opengl//
#include <GL\gl3w.h>

//STL
#include <iostream>

class FrameBuffer
{
public:

	FrameBuffer(float width, float height);

	//activate the framebuffer//
	void Bind() const;

	//get the texture//
	unsigned int GetTexture();

	//get the width//
	float GetWidth();

	//get the height//
	float GetHeight();

	//get the ratio//
	float GetRatio();

private:

	//identifier//
	unsigned int m_ID;

	//color texture//
	unsigned int m_Texture;

	//width//
	float m_Width;

	//height//
	float m_Height;

};