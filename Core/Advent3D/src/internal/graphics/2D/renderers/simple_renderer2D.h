#pragma once

//renderer super class
#include "renderer2D.h"

//double ended queue
#include <deque>

namespace advent { namespace graphics {

	class SimpleRenderer2D : public Renderer2D
	{

	private:
		std::deque<const Renderable2D*> m_RenderQueue;

	public:

		virtual void submit(const Renderable2D* renderable) override;
		virtual void flush() override;
	
	};

} }