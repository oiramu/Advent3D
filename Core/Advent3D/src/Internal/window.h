#pragma once

//opengl
#include <GL\gl3w.h>

//input
#include "input.h"

//glfw
#include <GLFW\glfw3.h>

class Window
{
public:

	Window(const char* title, float width, float heigth);

	bool Open() { return !glfwWindowShouldClose(m_Window); }
	
	void Clear();
	void Update();

	float GetWidth() { return m_Width; }
	float GetHeight() { return m_Height; }
	
	float GetRatio() { return m_Width / m_Height; }

	inline GLFWwindow* getHandle() const { return m_Window; }

	float deltaTime = 0.0f;

	~Window();

private:

	GLFWwindow* m_Window;

	const char* m_Title;
	
	float m_Width, m_Height;

	bool Init();

	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};