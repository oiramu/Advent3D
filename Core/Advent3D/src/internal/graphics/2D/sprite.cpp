#include "sprite.h"

namespace advent { namespace graphics { 

	Sprite::Sprite(const maths::vec3& position, const maths::vec2& size, const maths::vec4& color)
		: Renderable2D(position, size, color)
	{

	}

} }