#include "simple_renderer2D.h"

namespace advent { namespace graphics {

	void SimpleRenderer2D::submit(const Renderable2D* renderable)
	{
		m_RenderQueue.push_back(renderable);
	}

	void SimpleRenderer2D::flush()
	{
		while (!m_RenderQueue.empty())
		{
			const Renderable2D* renderable = m_RenderQueue.front();

			renderable->getVertexArray()->bind();
					  
			renderable->getIndexBuffer()->bind();
					  
			renderable->getShader().bind();
			renderable->getShader().setMat4("ml_matrix", maths::mat4::translation(renderable->getPosition()));
			renderable->getShader().setVec4("color", renderable->getColor());

			glDrawElements(GL_TRIANGLES, renderable->getIndexBuffer()->getCount(), GL_UNSIGNED_SHORT, nullptr);
					  
			renderable->getIndexBuffer()->unbind();
					  
			renderable->getVertexArray()->unbind();

			m_RenderQueue.pop_front();
		}
	}

} }