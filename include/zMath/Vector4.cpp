#include "Vector4.h"
#include <sstream>
#include "Math.h"

namespace zMath
{
	Vector4 const Vector4::zero = Vector4(0, 0, 0, 0);
	Vector4 const Vector4::one = Vector4(1, 1, 1, 1);

	Vector4::Vector4() : Vector4(0, 0, 0, 0)
	{
	}
	Vector4::Vector4(float x, float y, float z, float w) : x{x}, y{y}, z{z}, w{w}
	{
	}

	Vector4::Vector4(int x, int y, int z, int w) : x{ (float)x }, y{ (float)y }, z{ (float)z }, w{ (float)w }
	{
	}

	float Vector4::Length()
	{
		return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
	}
	float Vector4::LengthSq()
	{
		return Math::Sqrt(Length());
	}

	float Vector4::Dot(const Vector4& v)
	{
		return this->x * v.x + this->y * v.y + this->z * v.z + this->w + v.w;
	}

	void Vector4::Normalize()
	{
		float l = LengthSq();
		this->x /= l;
		this->y /= l;
		this->z /= l;
		this->w /= l;
	}

	float Vector4::Distance(const Vector4& a, const Vector4& b)
	{
		Vector4 dir = b - a;
		return dir.LengthSq();
	}

	Vector4 Vector4::MoveTo(const Vector4& current, const Vector4& target, float speed)
	{
		Vector4 dir = target - current;
		dir.Normalize();

		dir *= speed;

		return dir;
	}

	Vector4 Vector4::Lerp(const Vector4& a, const Vector4& b, float lerp)
	{
		lerp = Math::Clamp01(lerp);
		Vector4 l = Vector4(a.x + (b.x - a.x) * lerp, a.y + (b.y - a.y) * lerp, a.z + (b.z - a.z) * lerp, a.w + (b.w - a.w) * lerp);
		return l;
	}

	Vector4& Vector4::operator+=(const Vector4& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		this->w += v.w;

		return *this;
	}
	Vector4& Vector4::operator-=(const Vector4& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		this->w -= v.w;

		return *this;
	}
	Vector4& Vector4::operator*=(const Vector4& v)
	{
		this->x *= v.x;
		this->y *= v.y;
		this->z *= v.z;
		this->w *= v.w;

		return *this;
	}
	Vector4& Vector4::operator/=(const Vector4& v)
	{
		this->x /= v.x;
		this->y /= v.y;
		this->z /= v.z;
		this->w /= v.w;

		return *this;
	}

	Vector4& Vector4::operator*=(float s)
	{
		this->x *= s;
		this->y *= s;
		this->z *= s;
		this->w *= s;

		return *this;
	}
	Vector4& Vector4::operator/=(float d)
	{
		this->x /= d;
		this->y /= d;
		this->z /= d;
		this->w /= d;

		return *this;
	}

	std::string Vector4::ToString()
	{
		std::stringstream ss;

		ss << "{ x: " << this->x << ", y: " << this->y << ", z: " << this->z << ", w: " << this->w << " }";

		return ss.str();
	}
}
