#include "vector2.h"

namespace Advent3D {
	namespace Maths {

		Vector2::Vector2()
		{
			this->x = 0.0f;
			this->y = 0.0f;
		}

		Vector2::Vector2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		}

		Vector2& Vector2::Add(const Vector2& other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		Vector2& Vector2::Subtract(const Vector2& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		Vector2& Vector2::Multiply(const Vector2& other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		Vector2& Vector2::Divide(const Vector2& other)
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}

		Vector2& operator+ (Vector2& left, const Vector2& right)
		{
			return left.Add(right);
		}

		Vector2& operator- (Vector2& left, const Vector2& right)
		{
			return left.Subtract(right);
		}

		Vector2& operator* (Vector2& left, const Vector2& right)
		{
			return left.Multiply(right);
		}

		Vector2& operator/ (Vector2& left, const Vector2& right)
		{
			return left.Divide(right);
		}

		Vector2& Vector2::operator+= (const Vector2& other)
		{
			return Add(other);
		}

		Vector2& Vector2::operator-= (const Vector2& other)
		{
			return Subtract(other);
		}

		Vector2& Vector2::operator*= (const Vector2& other)
		{
			return Multiply(other);
		}

		Vector2& Vector2::operator/= (const Vector2& other)
		{
			return Divide(other);
		}

		std::ostream& operator<< (std::ostream& stream, const Vector2& vector)
		{
			stream << "Vector2: (" << vector.x << " , " << vector.y << ")";
			return stream;
		}
	}
}