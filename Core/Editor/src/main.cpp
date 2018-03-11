#include <Advent3D.h>

int main()
{
	Window window("Editor", 1366, 768);
	Shader shader("shader.shader");

	FrameBuffer fbo(1366,768);

#pragma region TRIANGLE

	float vertices[] =
	{
		-0.5f,-0.5f,
		0.0f,0.5f,
		0.5f,-0.5f
	};

	unsigned int indices[] =
	{
		0,1,2,2,3,0
	};

	unsigned int VAO;
	unsigned int VBO;
	unsigned int IBO;


	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


#pragma endregion

	while (window.Open())
	{
		//bind offscreen buffer//
		fbo.bind();
		//set clear color
		glClearColor(0.09f, 0.09f, 0.09f, 1.0f);
		//enable depth testing
		glEnable(GL_DEPTH_TEST);
		//clear
		glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);

		//draw the triangle
		shader.bind();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBindVertexArray(VAO);

		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);




		//DRAW ON THE DEFAULT BUFFER//
		fbo.unbind();
		window.Clear();

		glDisable(GL_DEPTH_TEST); 

		ImGui::BeginMainMenuBar();

		if (ImGui::BeginMenu("File"))
		{
			ImGui::MenuItem("New");
			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();

		ImGui::Begin("Scene");


		ImGui::GetWindowDrawList()->AddImage(
			(void *)fbo.GetTexture(),
			ImVec2(ImGui::GetCursorScreenPos()),
			ImVec2(ImGui::GetCursorScreenPos().x + fbo.GetWidth() / 2,
				ImGui::GetCursorScreenPos().y + fbo.GetHeight() / 2), ImVec2(0, 1), ImVec2(1, 0));

		ImGui::End();

		window.Update();
	}
	
	return 0;
}