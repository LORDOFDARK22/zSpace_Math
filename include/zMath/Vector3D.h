#pragma once
#include <ostream>
#include <string>

namespace zSpace_Math
{
	struct Vector3D
	{
		float x;
		float y;
		float z;

		Vector3D();
		Vector3D(float x, float y, float z);
		~Vector3D() = default;

		float Length();
		float LengthSq();
		float Dot(const Vector3D& v);
		Vector3D& Cross(const Vector3D& v);

		void Normalize();

		//Distance && Movment
		static float Distance(const Vector3D& a, const Vector3D& b);
		static Vector3D& MoveTo(const Vector3D& current, const Vector3D& target, float speed);
		static Vector3D& Lerp(const Vector3D& a, const Vector3D& b, float lerp);

		//operators + - * /
		Vector3D& operator+=(const Vector3D& v);
		Vector3D& operator-=(const Vector3D& v);
		Vector3D& operator*=(const Vector3D& v);
		Vector3D& operator/=(const Vector3D& v);

		Vector3D& operator*=(float s);
		Vector3D& operator/=(float d);

		//ostream tostring
		std::string ToString();

		//topdown
		static const Vector3D zero;
		static const Vector3D one;
		static const Vector3D up;
		static const Vector3D down;
		static const Vector3D left;
		static const Vector3D right;
		static const Vector3D forward;
		static const Vector3D back;
	};

	inline std::ostream& operator<<(std::ostream& os, const Vector3D& v)
	{
		return os << "{ x: " << v.x << ", y: " << v.y << ", z: " << v.z << " }";
	}

	static inline Vector3D& operator+(const Vector3D& a, const Vector3D& b)
	{
		Vector3D v{ a.x + b.x, a.y + b.y, a.z + b.z };
		return v;
	}
	static inline Vector3D& operator-(const Vector3D& a, const Vector3D& b)
	{
		Vector3D v{ a.x - b.x, a.y - b.y, a.z - b.z };
		return v;
	}
	static inline Vector3D& operator-(const Vector3D& v)
	{
		Vector3D s{ 0.0f - v.x, 0.0f - v.y, 0.0f - v.z };
		return s;
	}
	static inline Vector3D& operator*(const Vector3D& a, const Vector3D& b)
	{
		Vector3D v{ a.x * b.x, a.y * b.y, a.z * b.z };
		return v;
	}
	static inline Vector3D& operator/(const Vector3D& a, const Vector3D& b)
	{
		Vector3D v{ a.x / b.x, a.y / b.y, a.z / b.z };
		return v;
	}

	static inline Vector3D& operator*(const Vector3D& v, float a)
	{
		Vector3D s{ v.x * a, v.y * a, v.z * a};
		return s;
	}
	static inline Vector3D& operator*(float a, const Vector3D& v)
	{
		Vector3D s{ v.x * a, v.y * a, v.z * a };
		return s;
	}
	static inline Vector3D& operator/(const Vector3D& v, float a)
	{
		Vector3D d{ v.x / a, v.y / a, v.z / a };
		return d;
	}

	static inline bool operator==(const Vector3D& a, const Vector3D& b)
	{
		return (a.x == b.x && a.y == b.y && a.z == b.z);
	}
	static inline bool operator!=(const Vector3D& a, const Vector3D& b)
	{
		return !(a == b);
	}
}