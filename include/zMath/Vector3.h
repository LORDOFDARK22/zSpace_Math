#pragma once
#include <ostream>
#include <string>
#include <format>

namespace zMath
{
	struct Vector3
	{
		float x;
		float y;
		float z;

		Vector3();
		Vector3(float x, float y, float z);
		Vector3(int x, int y, int z);
		~Vector3() = default;

		float Length();
		float LengthSq();
		float Dot(const Vector3& v);
		Vector3 Cross(const Vector3& v);

		void Normalize();

		//Distance && Movment
		static float Distance(const Vector3& a, const Vector3& b);
		static Vector3 MoveTo(const Vector3& current, const Vector3& target, float speed);
		static Vector3 Lerp(const Vector3& a, const Vector3& b, float lerp);

		static Vector3 Reflect(Vector3& isDirection, const Vector3& isNormal);

		//operators + - * /
		Vector3& operator+=(const Vector3& v);
		Vector3& operator-=(const Vector3& v);
		Vector3& operator*=(const Vector3& v);
		Vector3& operator/=(const Vector3& v);

		Vector3& operator*=(float s);
		Vector3& operator/=(float d);

		//ostream tostring
		std::string ToString();

		//topdown
		static const Vector3 zero;
		static const Vector3 one;
		static const Vector3 up;
		static const Vector3 down;
		static const Vector3 left;
		static const Vector3 right;
		static const Vector3 forward;
		static const Vector3 back;
	};

	inline std::ostream& operator<<(std::ostream& os, const Vector3& v)
	{
		return os << "{ x: " << v.x << ", y: " << v.y << ", z: " << v.z << " }";
	}

	static inline Vector3 operator+(const Vector3& a, const Vector3& b)
	{
		return Vector3{ a.x + b.x, a.y + b.y, a.z + b.z };
	}
	static inline Vector3 operator-(const Vector3& a, const Vector3& b)
	{
		return Vector3{ a.x - b.x, a.y - b.y, a.z - b.z };
	}
	static inline Vector3 operator-(const Vector3& v)
	{
		return Vector3{ -v.x, -v.y, -v.z };
	}
	static inline Vector3 operator*(const Vector3& a, const Vector3& b)
	{
		return Vector3{ a.x * b.x, a.y * b.y, a.z * b.z };
	}
	static inline Vector3 operator/(const Vector3& a, const Vector3& b)
	{
		return Vector3{ a.x / b.x, a.y / b.y, a.z / b.z };
	}

	static inline Vector3 operator*(const Vector3& v, float a)
	{
		return Vector3{ v.x * a, v.y * a, v.z * a };
	}
	static inline Vector3 operator*(float a, const Vector3& v)
	{
		return Vector3{ v.x * a, v.y * a, v.z * a };
	}
	static inline Vector3 operator/(const Vector3& v, float a)
	{
		return Vector3{ v.x / a, v.y / a, v.z / a };
	}

	static inline bool operator==(const Vector3& a, const Vector3& b)
	{
		return (a.x == b.x && a.y == b.y && a.z == b.z);
	}
	static inline bool operator!=(const Vector3& a, const Vector3& b)
	{
		return !(a == b);
	}

	static inline bool operator>(const Vector3& a, const Vector3& b)
	{
		return (a.x > b.x && a.y > b.y && a.z > b.z);
	}
	static inline bool operator>=(const Vector3& a, const Vector3& b)
	{
		return (a.x >= b.x && a.y >= b.y && a.z >= b.z);
	}
	static inline bool operator<(const Vector3& a, const Vector3& b)
	{
		return (a.x < b.x && a.y < b.y && a.z < b.z);
	}
	static inline bool operator<=(const Vector3& a, const Vector3& b)
	{
		return (a.x <= b.x && a.y <= b.y && a.z <= b.z);
	}
}

template<>
struct std::formatter<zMath::Vector3> : std::formatter<std::string>
{
	auto format(const zMath::Vector3& v, std::format_context& ctx) const
	{
		return std::formatter<std::string>::format(std::format("( x{}, y{}, z{} )", v.x, v.y, v.z), ctx);
	}
};

namespace std
{
	template<>
	struct hash<zMath::Vector3>
	{
		size_t operator()(const zMath::Vector3& v) const noexcept
		{
			size_t seed = 0;
			seed ^= std::hash<float>{}(v.x) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			seed ^= std::hash<float>{}(v.y) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			seed ^= std::hash<float>{}(v.z) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			return seed;
		}
	};
}