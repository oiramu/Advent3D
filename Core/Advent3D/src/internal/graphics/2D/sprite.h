#pragma once

//renderable 2D super class
#include "renderable2D.h"

namespace advent { namespace graphics {

	//Sprites are just like renderables, but they can also contain textures(NOT IMPLEMENTED YET)
	class Sprite : public Renderable2D
	{

	public:

		//constructor
		Sprite(const maths::vec3& position, const maths::vec2& size, const maths::vec4& color);

	};

} }
