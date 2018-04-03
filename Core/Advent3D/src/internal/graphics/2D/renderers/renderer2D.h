#pragma once

#include "..\renderable2D.h"
#include "maths\maths.h"
#include <GL\gl3w.h>

namespace advent { namespace graphics {

	class Renderer2D
	{
		public:
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
	};

} }