#pragma once

#include "static_sprite.h"

namespace advent { namespace graphics {

	class Sprite : public Renderable2D
	{

	private:


	public:

		Sprite(const maths::vec3& position, const maths::vec2& size, const maths::vec4& color);

	};

} }
