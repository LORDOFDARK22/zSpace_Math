#include "Vector2.h"
#include <sstream>
#include "Math.h"

namespace zMath
{
	Vector2 const Vector2::zero = Vector2(0, 0);
	Vector2 const Vector2::one = Vector2(1, 1);
	Vector2 const Vector2::up = Vector2(0, 1);
	Vector2 const Vector2::down = Vector2(0, -1);
	Vector2 const Vector2::right = Vector2(1, 0);
	Vector2 const Vector2::left = Vector2(-1, 0);

	Vector2::Vector2() : Vector2(0, 0)
	{
	}
	Vector2::Vector2(float x, float y) : x{x}, y{y}
	{
	}
	Vector2::Vector2(int x, int y) : x{ (float)x }, y{ (float)y }
	{
	}
	float Vector2::Length()
	{
		//x^2 + y^2
		return this->x * this->x + this->y * this->y;
	}
	float Vector2::LengthSq()
	{
		//√(x^2 + y^2)
		return Math::sqrt(Length());
	}
	float Vector2::Dot(const Vector2& v)
	{
		//a ⋅ b = (a1 * b1) + (a2 * b2)
		return this->x * v.x + this->y * v.y;
	}
	Vector2 Vector2::Min(const Vector2& a, const Vector2& b)
	{
		if (a < b)
			return a;

		return b;
	}
	Vector2 Vector2::Max(const Vector2& a, const Vector2& b)
	{
		if (a > b)
			return a;

		return b;
	}
	void Vector2::Normalize()
	{
		float lnegthSq = LengthSq();
		this->x /= lnegthSq;
		this->y /= lnegthSq;
	}
	float Vector2::Distance(const Vector2& a, const Vector2& b)
	{
		Vector2 dir = b - a;
		return dir.LengthSq();
	}
	Vector2& Vector2::MoveTo(const Vector2& current, const Vector2& target, float speed)
	{
		Vector2 dir = target - current;
		dir.Normalize();

		dir *= speed;

		return dir;
	}
	Vector2& Vector2::Lerp(const Vector2& a, const Vector2& b, float lerp)
	{
		lerp = Math::Clamp01(lerp);
		Vector2 v = Vector2(a.x + (b.x - a.x) * lerp, a.y + (b.y - a.y) * lerp);
		return v;
	}
	Vector2& Vector2::operator+=(const Vector2& v)
	{
		this->x += v.x;
		this->y += v.y;

		return *this;
	}
	Vector2& Vector2::operator-=(const Vector2& v)
	{
		this->x -= v.x;
		this->y -= v.y;

		return *this;
	}
	Vector2& Vector2::operator*=(const Vector2& v)
	{
		this->x *= v.x;
		this->y *= v.y;

		return *this;
	}
	Vector2& Vector2::operator/=(const Vector2& v)
	{
		this->x /= v.x;
		this->y /= v.y;

		return *this;
	}
	Vector2& Vector2::operator*=(float s)
	{
		this->x *= s;
		this->y *= s;

		return *this;
	}
	Vector2& Vector2::operator/=(float d)
	{
		this->x /= d;
		this->y /= d;

		return *this;
	}
	std::string Vector2::ToString()
	{
		std::stringstream ss;

		ss << "{ x: " << this->x << ", y: " << this->y << " }";

		return ss.str();
	}
}
