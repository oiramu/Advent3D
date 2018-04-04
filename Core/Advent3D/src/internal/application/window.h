#pragma once

//opengl
#include <GL\gl3w.h>

//input
#include "input.h"

//glfw
#include <GLFW\glfw3.h>

#include "utils\timer.h"

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

	~Window();

private:

	GLFWwindow* m_Window;

	const char* m_Title;
	
	float m_Width, m_Height;

	//timer class used to calculate the frames per second
	utils::Timer m_Timer;
	int m_Frames = 0;
	float m_Time = 0;

	bool Init();

	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};

} }