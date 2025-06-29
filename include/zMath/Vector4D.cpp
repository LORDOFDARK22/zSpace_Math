#include "Vector4D.h"
#include <sstream>
#include "Math.h"

namespace zSpace_Math
{
	Vector4D const Vector4D::zero = Vector4D(0, 0, 0, 0);
	Vector4D const Vector4D::one = Vector4D(1, 1, 1, 1);

	Vector4D::Vector4D() : Vector4D(0, 0, 0, 0)
	{
	}
	Vector4D::Vector4D(float x, float y, float z, float w) : x{x}, y{y}, z{z}, w{w}
	{
	}

	float Vector4D::Length()
	{
		return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
	}
	float Vector4D::LengthSq()
	{
		return Math::sqrt(Length());
	}

	float Vector4D::Dot(const Vector4D& v)
	{
		return this->x * v.x + this->y * v.y + this->z * v.z + this->w + v.w;
	}

	void Vector4D::Normalize()
	{
		float l = LengthSq();
		this->x /= l;
		this->y /= l;
		this->z /= l;
		this->w /= l;
	}

	float Vector4D::Distance(const Vector4D& a, const Vector4D& b)
	{
		Vector4D dir = b - a;
		return dir.LengthSq();
	}

	Vector4D& Vector4D::MoveTo(const Vector4D& current, const Vector4D& target, float speed)
	{
		Vector4D dir = target - current;
		dir.Normalize();

		dir *= speed;

		return dir;
	}

	Vector4D& Vector4D::Lerp(const Vector4D& a, const Vector4D& b, float lerp)
	{
		lerp = Math::Clamp01(lerp);
		Vector4D l = Vector4D(a.x + (b.x - a.x) * lerp, a.y + (b.y - a.y) * lerp, a.z + (b.z - a.z) * lerp, a.w + (b.w - a.w) * lerp);
		return l;
	}

	Vector4D& Vector4D::operator+=(const Vector4D& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		this->w += v.w;

		return *this;
	}
	Vector4D& Vector4D::operator-=(const Vector4D& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		this->w -= v.w;

		return *this;
	}
	Vector4D& Vector4D::operator*=(const Vector4D& v)
	{
		this->x *= v.x;
		this->y *= v.y;
		this->z *= v.z;
		this->w *= v.w;

		return *this;
	}
	Vector4D& Vector4D::operator/=(const Vector4D& v)
	{
		this->x /= v.x;
		this->y /= v.y;
		this->z /= v.z;
		this->w /= v.w;

		return *this;
	}

	Vector4D& Vector4D::operator*=(float s)
	{
		this->x *= s;
		this->y *= s;
		this->z *= s;
		this->w *= s;

		return *this;
	}
	Vector4D& Vector4D::operator/=(float d)
	{
		this->x /= d;
		this->y /= d;
		this->z /= d;
		this->w /= d;

		return *this;
	}

	std::string Vector4D::ToString()
	{
		std::stringstream ss;

		ss << "{ x: " << this->x << ", y: " << this->y << ", z: " << this->z << ", w: " << this->w << " }";

		return ss.str();
	}
}
