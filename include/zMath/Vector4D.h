#pragma once
#include <ostream>
#include <string>

namespace zSpace_Math
{
	struct Vector4D
	{
		float x;
		float y;
		float z;
		float w;

		Vector4D();
		Vector4D(float x, float y, float z, float w);
		~Vector4D() = default;

		float Length();
		float LengthSq();
		float Dot(const Vector4D& v);

		void Normalize();

		//Distance && Movment
		static float Distance(const Vector4D& a, const Vector4D& b);
		static Vector4D& MoveTo(const Vector4D& current, const Vector4D& target, float speed);
		static Vector4D& Lerp(const Vector4D& a, const Vector4D& b, float lerp);

		//operators + - * /
		Vector4D& operator+=(const Vector4D& v);
		Vector4D& operator-=(const Vector4D& v);
		Vector4D& operator*=(const Vector4D& v);
		Vector4D& operator/=(const Vector4D& v);

		Vector4D& operator*=(float s);
		Vector4D& operator/=(float d);

		//ostream tostring
		std::string ToString();

		//topdown
		static const Vector4D zero;
		static const Vector4D one;
	};

	inline std::ostream& operator<<(std::ostream& os, const Vector4D& v)
	{
		return os << "{ x: " << v.x << ", y: " << v.y << ", z: " << v.z << ", w: " << v.w << " }";
	}

	static inline Vector4D& operator+(const Vector4D& a, const Vector4D& b)
	{
		Vector4D v{ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
		return v;
	}
	static inline Vector4D& operator-(const Vector4D& a, const Vector4D& b)
	{
		Vector4D v{ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
		return v;
	}
	static inline Vector4D& operator-(const Vector4D& v)
	{
		Vector4D s{ 0.0f - v.x, 0.0f - v.y, 0.0f - v.z, 0.0f + v.w };
		return s;
	}
	static inline Vector4D& operator*(const Vector4D& a, const Vector4D& b)
	{
		Vector4D v{ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
		return v;
	}
	static inline Vector4D& operator/(const Vector4D& a, const Vector4D& b)
	{
		Vector4D v{ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
		return v;
	}

	static inline Vector4D& operator*(const Vector4D& v, float a)
	{
		Vector4D s{ v.x * a, v.y * a, v.z * a, v.w * a };
		return s;
	}
	static inline Vector4D& operator*(float a, const Vector4D& v)
	{
		Vector4D s{ v.x * a, v.y * a, v.z * a, v.w * a };
		return s;
	}
	static inline Vector4D& operator/(const Vector4D& v, float a)
	{
		Vector4D d{ v.x / a, v.y / a, v.z / a, v.w / a };
		return d;
	}

	static inline bool operator==(const Vector4D& a, const Vector4D& b)
	{
		return (a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w);
	}
	static inline bool operator!=(const Vector4D& a, const Vector4D& b)
	{
		return !(a == b);
	}
}