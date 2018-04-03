#pragma once

//renderable2D
#include "..\renderable2D.h"

//maths
#include "maths\maths.h"

//opengl
#include <GL\gl3w.h>

namespace advent { namespace graphics {

	class Renderer2D
	{
		public:
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
	};

} }