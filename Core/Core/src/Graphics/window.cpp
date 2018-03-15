#include "window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);

	Input::mx = xpos;
	Input::my = ypos;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	Input::MouseButtons[button] = action != GLFW_RELEASE;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Input::Keys[key] = action != GLFW_RELEASE;
}

Window::Window(const char* title, float width, float heigth)
	:m_Title(title), m_Width(width),m_Height(heigth)
{
	if (!Init())
		glfwTerminate();
}

bool Window::Init()
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

	if (!m_Window)
	{
		std::cout << "Failed to create GLFWwindow" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_Window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwSetWindowUserPointer(m_Window, this);

	glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

	glfwSetKeyCallback(m_Window, key_callback);

	glfwSetMouseButtonCallback(m_Window, mouse_button_callback);

	glfwSetCursorPosCallback(m_Window, cursor_position_callback);

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui_ImplGlfwGL3_Init(m_Window, true);

	ImGui::StyleColorsDark();

	return true;
}

void Window::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwPollEvents();
	ImGui_ImplGlfwGL3_NewFrame();
}

void Window::Update()
{
	float m_LastFrame = 0.0f;
	float currentFrame = glfwGetTime();

	deltaTime = currentFrame - m_LastFrame;
	m_LastFrame = currentFrame;

	ImGui::Render();
	ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
	glfwGetWindowSize(m_Window, (int*)&m_Width, (int*)&m_Height);
	glfwSwapBuffers(m_Window);
}

Window::~Window()
{
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
}
