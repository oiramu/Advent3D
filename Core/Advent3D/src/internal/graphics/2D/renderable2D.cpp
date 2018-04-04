#include "renderable2D.h"

namespace advent { namespace graphics {

	//just setup the constructor, we don't need to fill it in with too much stuff, since we just use as a super class
	Renderable2D::Renderable2D(const maths::vec3& position, const maths::vec2& size, const maths::vec4& color)
		: m_Position(position), m_Size(size), m_Color(color) {}

} }