#include "renderable2D.h"

namespace advent { namespace graphics {

	Renderable2D::Renderable2D(const maths::vec3& position, const maths::vec2& size, const maths::vec4& color)
		: m_Position(position), m_Size(size), m_Color(color) {}

	Renderable2D::~Renderable2D() { }

} }