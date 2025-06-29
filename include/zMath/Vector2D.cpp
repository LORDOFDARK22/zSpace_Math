#include "Vector2D.h"
#include <sstream>
#include "Math.h"

namespace zSpace_Math
{
	Vector2D const Vector2D::zero = Vector2D(0, 0);
	Vector2D const Vector2D::one = Vector2D(1, 1);
	Vector2D const Vector2D::up = Vector2D(0, 1);
	Vector2D const Vector2D::down = Vector2D(0, -1);
	Vector2D const Vector2D::right = Vector2D(1, 0);
	Vector2D const Vector2D::left = Vector2D(-1, 0);

	Vector2D::Vector2D() : Vector2D(0, 0)
	{
	}
	Vector2D::Vector2D(float x, float y) : x{x}, y{y}
	{
	}
	float Vector2D::Length()
	{
		//x^2 + y^2
		return this->x * this->x + this->y * this->y;
	}
	float Vector2D::LengthSq()
	{
		//√(x^2 + y^2)
		return Math::sqrt(Length());
	}
	float Vector2D::Dot(const Vector2D& v)
	{
		//a ⋅ b = (a1 * b1) + (a2 * b2)
		return this->x * v.x + this->y * v.y;
	}
	void Vector2D::Normalize()
	{
		float lnegthSq = LengthSq();
		this->x /= lnegthSq;
		this->y /= lnegthSq;
	}
	float Vector2D::Distance(const Vector2D& a, const Vector2D& b)
	{
		Vector2D dir = b - a;
		return dir.LengthSq();
	}
	Vector2D& Vector2D::MoveTo(const Vector2D& current, const Vector2D& target, float speed)
	{
		Vector2D dir = target - current;
		dir.Normalize();

		dir *= speed;

		return dir;
	}
	Vector2D& Vector2D::Lerp(const Vector2D& a, const Vector2D& b, float lerp)
	{
		lerp = Math::Clamp01(lerp);
		Vector2D v = Vector2D(a.x + (b.x - a.x) * lerp, a.y + (b.y - a.y) * lerp);
		return v;
	}
	Vector2D& Vector2D::operator+=(const Vector2D& v)
	{
		this->x += v.x;
		this->y += v.y;

		return *this;
	}
	Vector2D& Vector2D::operator-=(const Vector2D& v)
	{
		this->x -= v.x;
		this->y -= v.y;

		return *this;
	}
	Vector2D& Vector2D::operator*=(const Vector2D& v)
	{
		this->x *= v.x;
		this->y *= v.y;

		return *this;
	}
	Vector2D& Vector2D::operator/=(const Vector2D& v)
	{
		this->x /= v.x;
		this->y /= v.y;

		return *this;
	}
	Vector2D& Vector2D::operator*=(float s)
	{
		this->x *= s;
		this->y *= s;

		return *this;
	}
	Vector2D& Vector2D::operator/=(float d)
	{
		this->x /= d;
		this->y /= d;

		return *this;
	}
	std::string Vector2D::ToString()
	{
		std::stringstream ss;

		ss << "{ x: " << this->x << ", y: " << this->y << " }";

		return ss.str();
	}
}
