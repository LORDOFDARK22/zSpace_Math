#pragma once
#include <ostream>
#include <string>

namespace zMath
{
	struct Vector2
	{
		float x;
		float y;

		Vector2();
		Vector2(float x, float y);
		Vector2(int x, int y);
		~Vector2() = default;

		float Length();
		float LengthSq();
		float Dot(const Vector2& v);

		Vector2 Min(const Vector2& a, const Vector2& b);
		Vector2 Max(const Vector2& a, const Vector2& b);

		float Angle(const Vector2& from, const Vector2& to);

		void Normalize();

		//Distance && Movment
		static float Distance(const Vector2& a, const Vector2& b);
		static Vector2& MoveTo(const Vector2& current, const Vector2& target, float speed);
		static Vector2& Lerp(const Vector2& a, const Vector2& b, float lerp);

		//operators + - * /
		Vector2& operator+=(const Vector2& v);
		Vector2& operator-=(const Vector2& v);
		Vector2& operator*=(const Vector2& v);
		Vector2& operator/=(const Vector2& v);

		Vector2& operator*=(float s);
		Vector2& operator/=(float d);

		//ostream tostring
		std::string ToString();

		//topdown
		static const Vector2 zero;
		static const Vector2 one;
		static const Vector2 up;
		static const Vector2 down;
		static const Vector2 left;
		static const Vector2 right;
	};

	inline std::ostream& operator<<(std::ostream& os, const Vector2& v)
	{
		return os << "{ x: " << v.x << ", y: " << v.y << " }";
	}
	
	static inline Vector2& operator+(const Vector2& a, const Vector2& b)
	{
		Vector2 v{ a.x + b.x, a.y + b.y };
		return v;
	}
	static inline Vector2& operator-(const Vector2& a, const Vector2& b)
	{
		Vector2 v{ a.x - b.x, a.y - b.y };
		return v;
	}
	static inline Vector2& operator-(const Vector2& v)
	{
		Vector2 s{ 0.0f - v.x, 0.0f - v.y };
		return s;
	}
	static inline Vector2& operator*(const Vector2& a, const Vector2& b)
	{
		Vector2 v{ a.x * b.x, a.y * b.y };
		return v;
	}
	static inline Vector2& operator/(const Vector2& a, const Vector2& b)
	{
		Vector2 v{ a.x / b.x, a.y / b.y };
		return v;
	}

	static inline Vector2& operator*(const Vector2& v, float a)
	{
		Vector2 s{ v.x * a, v.y * a };
		return s;
	}
	static inline Vector2& operator*(float a, const Vector2& v)
	{
		Vector2 s{ v.x * a, v.y * a };
		return s;
	}
	static inline Vector2& operator/(const Vector2& v, float a)
	{
		Vector2 d{ v.x / a, v.y / a };
		return d;
	}

	static inline bool operator==(const Vector2& a, const Vector2& b)
	{
		return (a.x == b.x && a.y == b.y);
	}
	static inline bool operator!=(const Vector2& a, const Vector2& b)
	{
		return !(a == b);
	}

	static inline bool operator>(const Vector2 & a, const Vector2 & b)
	{
		return (a.x > b.x && a.y > b.y);
	}
	static inline bool operator>=(const Vector2& a, const Vector2& b)
	{
		return (a.x >= b.x && a.y >= b.y);
	}
	static inline bool operator<(const Vector2& a, const Vector2& b)
	{
		return (a.x < b.x && a.y < b.y);
	}
	static inline bool operator<=(const Vector2& a, const Vector2& b)
	{
		return (a.x <= b.x && a.y <= b.y);
	}
}