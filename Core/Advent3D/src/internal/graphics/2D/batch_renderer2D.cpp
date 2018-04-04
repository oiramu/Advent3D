#include "batch_renderer2D.h"

namespace advent { namespace graphics {

	BatchRenderer2D::BatchRenderer2D()
	{
		Init();
	}

	void BatchRenderer2D::Init()
	{
		//generate the vertex array and the buffer
		glGenVertexArrays(1, &m_VertexArray);
		glGenBuffers(1, &m_Buffer);
		glGenBuffers(1, &m_IndexBuffer);

		//bind the vertex array and the buffer
		glBindVertexArray(m_VertexArray);
		glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);

		//specify the buffer data
		//we don't know yet which type of data we are passing in, so we put NULL.
		//since we are going to modify the buffer constantly, we use GL_DYNAMIC_DRAW
		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

		//set the attributes, specifying how the data inside the VertexData struct is arranged
		//the index DEPENDS ON THE RENDERER, not the shader.
		glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE,(const GLvoid*) 0);
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)(3 * sizeof(GLfloat)));

		//let's not forget to enable the correct vertex attributes
		glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);

		//unbind the buffer now, since we are not using it anymore
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		//generate the indices
		GLushort indices[RENDERER_INDICES_SIZE];

		int offset = 0;

		//loop. we do += 6, since we are generating indices for each sprite
		for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
		{
			indices[i] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;
			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;
			
			//since there are 4 vertices, not 6, we need to add 4 to offset:
			offset += 4;
		}

		//feed all the indices to the index buffer
		//bind the indexbuffer. Since we are not going to modify the index buffer constantly, we put GL_STATIC_DRAW as "mode"
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, RENDERER_INDICES_SIZE, indices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		//finally, unbind the vertex array
		glBindVertexArray(0);

	}

	//maps the buffer
	void BatchRenderer2D::begin()
	{
		//first thing we need to do is bind the buffer
		glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);

		//we want to map an array of elements, and we only want to write to this buffer, not read or read and write
		//glMapBuffer returns a void pointer to the very first byte of data of the buffer we created earlier, so we need to cast it to a VertexData*
		m_VertexData = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

	}

	//passes everything straight to Opengl, without storing any type if data using buffer mapping
	void BatchRenderer2D::submit(const Renderable2D* renderable)
	{
		//just some helpers to make the code more readable 
		const maths::vec3& position = renderable->getPosition();
		const maths::vec2& size = renderable->getSize();
		const maths::vec4& color = renderable->getColor();

		//here is the cool stuff: since we casted buffer to a VertexData*, now we can do things like buffer->vertex or buffer->color
		m_VertexData->vertex = position;
		m_VertexData->color = color;
		
		//so now, the memory will get interpreted as a VertexData.
		//by doing buffer++, we simply advance by 28 bytes of memory.
		//we don't really need an offset, since the buffer itself is what's needed to advance to the next element
		m_VertexData++;

		//do the same for the other 3 elements of the quad
		//the position of the vertex also depends on the size, so we need to also add that in 
		m_VertexData->vertex = maths::vec3(position.x, position.y + size.y, position.z);
		m_VertexData->color = color;
		m_VertexData++;

		m_VertexData->vertex = maths::vec3(position.x + size.x, position.y + size.y, position.z);
		m_VertexData->color = color;
		m_VertexData++;

		m_VertexData->vertex = maths::vec3(position.x + size.x, position.y, position.z);
		m_VertexData->color = color;
		m_VertexData++;

		//increase the count of indices
		m_IndexCount += 6;

		//TODO: check if the buffer is overflowing
	}

	//unmap the buffer
	void BatchRenderer2D::end()
	{
		//IMPORTANT: if you don't unmap the buffer, you won't be able to draw!
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	//performs the drawcall
	void BatchRenderer2D::flush()
	{
		//bind the vertex array and the index buffer
		glBindVertexArray(m_VertexArray);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);

		//perform the draw call
		glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, NULL);

		//unbind everything
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		//after we render everything, we need to reset the index count
		m_IndexCount = 0;
	}

	BatchRenderer2D::~BatchRenderer2D()
	{
		//clean up
		glDeleteBuffers(1, &m_Buffer);
		glDeleteBuffers(1, &m_IndexBuffer);
		glDeleteVertexArrays(1, &m_VertexArray);
	}

} }