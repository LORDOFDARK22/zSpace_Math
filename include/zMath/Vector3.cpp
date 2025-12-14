#include "Vector3.h"
#include <sstream>
#include "Math.h"

namespace zMath
{
	Vector3 const Vector3::zero = Vector3(0, 0, 0);
	Vector3 const Vector3::one = Vector3(1, 1, 1);
	Vector3 const Vector3::up = Vector3(0, 1, 0);
	Vector3 const Vector3::down = Vector3(0, -1, 0);
	Vector3 const Vector3::right = Vector3(1, 0, 0);
	Vector3 const Vector3::left = Vector3(-1, 0, 0);
	Vector3 const Vector3::forward = Vector3(0, 0, 1);
	Vector3 const Vector3::back = Vector3(0, 0, -1);

	Vector3::Vector3() : Vector3(0, 0, 0)
	{
	}
	Vector3::Vector3(float x, float y, float z) : x{x}, y{y}, z{z}
	{
	}

	Vector3::Vector3(int x, int y, int z) : x{(float)x}, y{ (float)y }, z{ (float)z }
	{
	}

	float Vector3::Length()
	{
		return x * x + y * y + z * z;
	}
	float Vector3::LengthSq()
	{
		return Math::Sqrt(Length());
	}

	float Vector3::Dot(const Vector3& v)
	{
		return this->x * v.x + this->y * v.y + this->z * v.z;
	}

	Vector3 Vector3::Cross(const Vector3& v)
	{
		Vector3 crossed = Vector3(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
		return crossed;
	}

	void Vector3::Normalize()
	{
		float l = LengthSq();
		this->x /= l;
		this->y /= l;
		this->z /= l;
	}

	float Vector3::Distance(const Vector3& a, const Vector3& b)
	{
		Vector3 dir = b - a;
		return dir.LengthSq();
	}

	Vector3 Vector3::MoveTo(const Vector3& current, const Vector3& target, float speed)
	{
		Vector3 dir = target - current;
		dir.Normalize();

		dir *= speed;

		return dir;
	}

	Vector3 Vector3::Lerp(const Vector3& a, const Vector3& b, float lerp)
	{
		lerp = Math::Clamp01(lerp);
		Vector3 l = Vector3(a.x + (b.x - a.x) * lerp, a.y + (b.y - a.y) * lerp, a.z + (b.z - a.z) * lerp);
		return l;
	}

	Vector3 Vector3::Reflect(Vector3& isDirection, const Vector3& isNormal)
	{
		float dot = isDirection.Dot(isNormal);
		Vector3 reflect = isDirection - 2.0f * dot * isNormal;
		return reflect;
	}

	std::string Vector3::ToString()
	{
		std::stringstream ss;

		ss << "{ x: " << this->x << ", y: " << this->y << ", z: " << this->z << " }";

		return ss.str();
	}

	Vector3& Vector3::operator+=(const Vector3& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;

		return *this;
	}
	Vector3& Vector3::operator-=(const Vector3& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;

		return *this;
	}
	Vector3& Vector3::operator*=(const Vector3& v)
	{
		this->x *= v.x;
		this->y *= v.y;
		this->z *= v.z;

		return *this;
	}
	Vector3& Vector3::operator/=(const Vector3& v)
	{
		this->x /= v.x;
		this->y /= v.y;
		this->z /= v.z;

		return *this;
	}

	Vector3& Vector3::operator*=(float s)
	{
		this->x *= s;
		this->y *= s;
		this->z *= s;

		return *this;
	}
	Vector3& Vector3::operator/=(float d)
	{
		this->x /= d;
		this->y /= d;
		this->z /= d;

		return *this;
	}
}