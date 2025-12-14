#pragma once
#include <ostream>
#include <string>
#include <format>

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
	

	// ✅ رجع بالقيمة وليس بالـ reference
	static inline Vector2 operator+(const Vector2& a, const Vector2& b)
	{
		return Vector2{ a.x + b.x, a.y + b.y };
	}
	static inline Vector2 operator-(const Vector2& a, const Vector2& b)
	{
		return Vector2{ a.x - b.x, a.y - b.y };
	}
	static inline Vector2 operator-(const Vector2& v)
	{
		return Vector2{ -v.x, -v.y };
	}
	static inline Vector2 operator*(const Vector2& a, const Vector2& b)
	{
		return Vector2{ a.x * b.x, a.y * b.y };
	}
	static inline Vector2 operator/(const Vector2& a, const Vector2& b)
	{
		return Vector2{ a.x / b.x, a.y / b.y };
	}
	static inline Vector2 operator*(const Vector2& v, float a)
	{
		return Vector2{ v.x * a, v.y * a };
	}
	static inline Vector2 operator*(float a, const Vector2& v)
	{
		return Vector2{ v.x * a, v.y * a };
	}
	static inline Vector2 operator/(const Vector2& v, float a)
	{
		return Vector2{ v.x / a, v.y / a };
	}

	static inline bool operator==(const Vector2& a, const Vector2& b)
	{
		return (a.x == b.x && a.y == b.y);
	}
	static inline bool operator!=(const Vector2& a, const Vector2& b)
	{
		return !(a == b);
	}

	static inline bool operator>(const Vector2& a, const Vector2& b)
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

template<>
struct std::formatter<zMath::Vector2> : std::formatter<std::string>
{
	auto format(const zMath::Vector2& v, std::format_context& ctx) const
	{
		return std::formatter<std::string>::format(std::format("( x{}, y{} )", v.x, v.y), ctx);
	}
};

namespace std
{
	template<>
	struct hash<zMath::Vector2>
	{
		size_t operator()(const zMath::Vector2& v) const noexcept
		{
			size_t hx = std::hash<float>{}(v.x);
			size_t hy = std::hash<float>{}(v.y);
			return hx ^ (hy << 1);
		}
	};
}