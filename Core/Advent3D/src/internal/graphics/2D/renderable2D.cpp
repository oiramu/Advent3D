#include "renderable2D.h"

namespace advent { namespace graphics {

	Renderable2D::Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color, Shader& shader) 
		: m_Position(position), m_Size(size), m_Color(color), m_Shader(shader)
	{
		GLfloat vertices[] = 
		{
			0,0,0,
			0, m_Size.y, 0,
			m_Size.x,m_Size.y,0,
			m_Size.x,0,0
		};

		GLfloat colors[] =
		{
			m_Color.x,m_Color.y,m_Color.z,m_Color.w,
			m_Color.x,m_Color.y,m_Color.z,m_Color.w,
			m_Color.x,m_Color.y,m_Color.z,m_Color.w,
			m_Color.x,m_Color.y,m_Color.z,m_Color.w
		};

		GLushort indices[6] = {0,1,2,2,3,0};

		m_VertexArray = new VertexArray();
		m_IndexBuffer = new IndexBuffer(indices, 6);

		m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
		m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);
	}

	Renderable2D::~Renderable2D()
	{
		delete m_VertexArray;
		delete m_IndexBuffer;
	}

} }