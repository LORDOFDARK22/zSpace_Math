#include "Vector3D.h"
#include <sstream>
#include "Math.h"

namespace zSpace_Math
{
	Vector3D const Vector3D::zero = Vector3D(0, 0, 0);
	Vector3D const Vector3D::one = Vector3D(1, 1, 1);
	Vector3D const Vector3D::up = Vector3D(0, 1, 0);
	Vector3D const Vector3D::down = Vector3D(0, -1, 0);
	Vector3D const Vector3D::right = Vector3D(1, 0, 0);
	Vector3D const Vector3D::left = Vector3D(-1, 0, 0);
	Vector3D const Vector3D::forward = Vector3D(0, 0, 1);
	Vector3D const Vector3D::back = Vector3D(0, 0, -1);

	Vector3D::Vector3D() : Vector3D(0, 0, 0)
	{
	}
	Vector3D::Vector3D(float x, float y, float z) : x{x}, y{y}, z{z}
	{
	}

	float Vector3D::Length()
	{
		return x * x + y * y + z * z;
	}
	float Vector3D::LengthSq()
	{
		return Math::sqrt(Length());
	}

	float Vector3D::Dot(const Vector3D& v)
	{
		return this->x * v.x + this->y * v.y + this->z * v.z;
	}

	Vector3D& Vector3D::Cross(const Vector3D& v)
	{
		Vector3D crossed = Vector3D(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
		return crossed;
	}

	void Vector3D::Normalize()
	{
		float l = LengthSq();
		this->x /= l;
		this->y /= l;
		this->z /= l;
	}

	float Vector3D::Distance(const Vector3D& a, const Vector3D& b)
	{
		Vector3D dir = b - a;
		return dir.LengthSq();
	}

	Vector3D& Vector3D::MoveTo(const Vector3D& current, const Vector3D& target, float speed)
	{
		Vector3D dir = target - current;
		dir.Normalize();

		dir *= speed;

		return dir;
	}

	Vector3D& Vector3D::Lerp(const Vector3D& a, const Vector3D& b, float lerp)
	{
		lerp = Math::Clamp01(lerp);
		Vector3D l = Vector3D(a.x + (b.x - a.x) * lerp, a.y + (b.y - a.y) * lerp, a.z + (b.z - a.z) * lerp);
		return l;
	}

	std::string Vector3D::ToString()
	{
		std::stringstream ss;

		ss << "{ x: " << this->x << ", y: " << this->y << ", z: " << this->z << " }";

		return ss.str();
	}

	Vector3D& Vector3D::operator+=(const Vector3D& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;

		return *this;
	}
	Vector3D& Vector3D::operator-=(const Vector3D& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;

		return *this;
	}
	Vector3D& Vector3D::operator*=(const Vector3D& v)
	{
		this->x *= v.x;
		this->y *= v.y;
		this->z *= v.z;

		return *this;
	}
	Vector3D& Vector3D::operator/=(const Vector3D& v)
	{
		this->x /= v.x;
		this->y /= v.y;
		this->z /= v.z;

		return *this;
	}

	Vector3D& Vector3D::operator*=(float s)
	{
		this->x *= s;
		this->y *= s;
		this->z *= s;

		return *this;
	}
	Vector3D& Vector3D::operator/=(float d)
	{
		this->x /= d;
		this->y /= d;
		this->z /= d;

		return *this;
	}
}