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
	//set the callbacks
	glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

	glfwSetKeyCallback(m_Window, key_callback);

	glfwSetMouseButtonCallback(m_Window, mouse_button_callback);

	glfwSetCursorPosCallback(m_Window, cursor_position_callback);

	//init glfw
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return false;
	}

	//create the window
	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

	glfwSetWindowUserPointer(m_Window, this);
	
	//check if the window has been created successfully
	if (!m_Window)
	{
		std::cout << "Failed to create GLFWwindow" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_Window);

	//initialize gl
	gl3wInit();

	//create a context for imgui
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui_ImplGlfwGL3_Init(m_Window, true);

	//setup the style
	ImGui::StyleColorsDark();

	//(TEMPORARY) enable depth test
	glEnable(GL_DEPTH_TEST);

	//print out the opengl version
	std::cout << "Running on Opengl " << glGetString(GL_VERSION) << std::endl;

	return true;
}

void Window::Clear()
{
	//clear the color and depth buffer bit
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glfwPollEvents();

	ImGui_ImplGlfwGL3_NewFrame();
}

void Window::Update()
{
	//calculate the deltatime
	float m_LastFrame = 0.0f;
	float currentFrame = glfwGetTime();

	deltaTime = currentFrame - m_LastFrame;
	m_LastFrame = currentFrame;

	//render imgui data
	ImGui::Render();
	ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
	
	//reset width and height
	glfwGetWindowSize(m_Window, (int*)&m_Width, (int*)&m_Height);
	
	//swap the buffers
	glfwSwapBuffers(m_Window);
}

Window::~Window()
{
	//clean up
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
}
