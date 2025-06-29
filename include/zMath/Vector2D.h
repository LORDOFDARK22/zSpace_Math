#pragma once
#include <ostream>
#include <string>

namespace zSpace_Math
{
	struct Vector2D
	{
		float x;
		float y;

		Vector2D();
		Vector2D(float x, float y);
		~Vector2D() = default;

		float Length();
		float LengthSq();
		float Dot(const Vector2D& v);

		Vector2D& Min(const Vector2D& a, const Vector2D& b);
		Vector2D& Max(const Vector2D& a, const Vector2D& b);

		float Angle(const Vector2D& from, const Vector2D& to);

		void Normalize();

		//Distance && Movment
		static float Distance(const Vector2D& a, const Vector2D& b);
		static Vector2D& MoveTo(const Vector2D& current, const Vector2D& target, float speed);
		static Vector2D& Lerp(const Vector2D& a, const Vector2D& b, float lerp);

		//operators + - * /
		Vector2D& operator+=(const Vector2D& v);
		Vector2D& operator-=(const Vector2D& v);
		Vector2D& operator*=(const Vector2D& v);
		Vector2D& operator/=(const Vector2D& v);

		Vector2D& operator*=(float s);
		Vector2D& operator/=(float d);

		//ostream tostring
		std::string ToString();

		//topdown
		static const Vector2D zero;
		static const Vector2D one;
		static const Vector2D up;
		static const Vector2D down;
		static const Vector2D left;
		static const Vector2D right;
	};

	inline std::ostream& operator<<(std::ostream& os, const Vector2D& v)
	{
		return os << "{ x: " << v.x << ", y: " << v.y << " }";
	}
	
	static inline Vector2D& operator+(const Vector2D& a, const Vector2D& b)
	{
		Vector2D v{ a.x + b.x, a.y + b.y };
		return v;
	}
	static inline Vector2D& operator-(const Vector2D& a, const Vector2D& b)
	{
		Vector2D v{ a.x - b.x, a.y - b.y };
		return v;
	}
	static inline Vector2D& operator-(const Vector2D& v)
	{
		Vector2D s{ 0.0f - v.x, 0.0f - v.y };
		return s;
	}
	static inline Vector2D& operator*(const Vector2D& a, const Vector2D& b)
	{
		Vector2D v{ a.x * b.x, a.y * b.y };
		return v;
	}
	static inline Vector2D& operator/(const Vector2D& a, const Vector2D& b)
	{
		Vector2D v{ a.x / b.x, a.y / b.y };
		return v;
	}

	static inline Vector2D& operator*(const Vector2D& v, float a)
	{
		Vector2D s{ v.x * a, v.y * a };
		return s;
	}
	static inline Vector2D& operator*(float a, const Vector2D& v)
	{
		Vector2D s{ v.x * a, v.y * a };
		return s;
	}
	static inline Vector2D& operator/(const Vector2D& v, float a)
	{
		Vector2D d{ v.x / a, v.y / a };
		return d;
	}

	static inline bool operator==(const Vector2D& a, const Vector2D& b)
	{
		return (a.x == b.x && a.y == b.y);
	}
	static inline bool operator!=(const Vector2D& a, const Vector2D& b)
	{
		return !(a == b);
	}
}