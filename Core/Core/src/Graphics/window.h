#pragma once

#include <GL\glew.h>
#include "..\Logic\Input\input.h"
#include <GLM\vec2.hpp>

//basic window class for context creation and input handling//

class Window
{
public:

	Window(const char* title, const int& sizeX, const int& sizeY);

	bool Open() { return !glfwWindowShouldClose(m_Window); }
	
	void Clear();
	void Update();

	glm::vec2 getSize() const { return m_Size; }

	inline GLFWwindow* getHandle() const { return m_Window; }

	float deltaTime = 0.0f;

	~Window();

private:

	GLFWwindow* m_Window;

	const char* m_Title;
	const glm::vec2 m_Size;

	bool Init();

	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};