#pragma once

//opengl
#include <GL\gl3w.h>

//input
#include "input.h"

//glfw
#include <GLFW\glfw3.h>

namespace advent { namespace graphics {

class Window
{
public:

	Window(const char* title, float width, float heigth);

	inline bool Open() const { return !glfwWindowShouldClose(m_Window); }
	
	void Clear() const;
	void Update();
	void SetClearColor(float r, float b, float g) const;

	inline float GetWidth() const { return m_Width; }
	inline float GetHeight() const { return m_Height; }
	
	inline float GetRatio() const { return m_Width / m_Height; }

	inline GLFWwindow* getHandle() const { return m_Window; }

	float deltaTime = 0.0f;

	~Window();

private:

	GLFWwindow* m_Window;

	const char* m_Title;
	
	float m_Width, m_Height;

	float m_LastFrame = 0.0f;

	bool Init();

	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};

} }