#include "static_sprite.h"

namespace advent { namespace graphics {

	StaticSprite::StaticSprite(const maths::vec3& position, const maths::vec2& size, const maths::vec4& color, Shader& shader)
		:Renderable2D(position,size,color), m_Shader(shader)
	{
		GLfloat vertices[] =
		{
			0,0,0,
			0, size.y, 0,
			size.x,size.y,0,
			size.x,0,0
		};

		GLfloat colors[] =
		{
			color.x,color.y,color.z,color.w,
			color.x,color.y,color.z,color.w,
			color.x,color.y,color.z,color.w,
			color.x,color.y,color.z,color.w
		};

		GLushort indices[6] = { 0,1,2,2,3,0 };

		m_VertexArray = new VertexArray();
		m_IndexBuffer = new IndexBuffer(indices, 6);

		m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
		m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);
	}

	StaticSprite::~StaticSprite()
	{
		delete m_VertexArray;
		delete m_IndexBuffer;
	}

} }