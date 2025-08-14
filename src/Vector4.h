#pragma once
#include <ostream>
#include <string>

namespace zMath
{
	struct Vector4
	{
		float x;
		float y;
		float z;
		float w;

		Vector4();
		Vector4(float x, float y, float z, float w);
		Vector4(int x, int y, int z, int w);
		~Vector4() = default;

		float Length();
		float LengthSq();
		float Dot(const Vector4& v);

		void Normalize();

		//Distance && Movment
		static float Distance(const Vector4& a, const Vector4& b);
		static Vector4 MoveTo(const Vector4& current, const Vector4& target, float speed);
		static Vector4 Lerp(const Vector4& a, const Vector4& b, float lerp);

		//operators + - * /
		Vector4& operator+=(const Vector4& v);
		Vector4& operator-=(const Vector4& v);
		Vector4& operator*=(const Vector4& v);
		Vector4& operator/=(const Vector4& v);

		Vector4& operator*=(float s);
		Vector4& operator/=(float d);

		//ostream tostring
		std::string ToString();

		//topdown
		static const Vector4 zero;
		static const Vector4 one;
	};

	inline std::ostream& operator<<(std::ostream& os, const Vector4& v)
	{
		return os << "{ x: " << v.x << ", y: " << v.y << ", z: " << v.z << ", w: " << v.w << " }";
	}

	static inline Vector4& operator+(const Vector4& a, const Vector4& b)
	{
		Vector4 v{ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
		return v;
	}
	static inline Vector4& operator-(const Vector4& a, const Vector4& b)
	{
		Vector4 v{ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
		return v;
	}
	static inline Vector4& operator-(const Vector4& v)
	{
		Vector4 s{ 0.0f - v.x, 0.0f - v.y, 0.0f - v.z, 0.0f + v.w };
		return s;
	}
	static inline Vector4& operator*(const Vector4& a, const Vector4& b)
	{
		Vector4 v{ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
		return v;
	}
	static inline Vector4& operator/(const Vector4& a, const Vector4& b)
	{
		Vector4 v{ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
		return v;
	}

	static inline Vector4& operator*(const Vector4& v, float a)
	{
		Vector4 s{ v.x * a, v.y * a, v.z * a, v.w * a };
		return s;
	}
	static inline Vector4& operator*(float a, const Vector4& v)
	{
		Vector4 s{ v.x * a, v.y * a, v.z * a, v.w * a };
		return s;
	}
	static inline Vector4& operator/(const Vector4& v, float a)
	{
		Vector4 d{ v.x / a, v.y / a, v.z / a, v.w / a };
		return d;
	}

	static inline bool operator==(const Vector4& a, const Vector4& b)
	{
		return (a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w);
	}
	static inline bool operator!=(const Vector4& a, const Vector4& b)
	{
		return !(a == b);
	}

	static inline bool operator>(const Vector4& a, const Vector4& b)
	{
		return (a.x > b.x && a.y > b.y && a.z > b.z && a.w > b.w);
	}
	static inline bool operator>=(const Vector4& a, const Vector4& b)
	{
		return (a.x >= b.x && a.y >= b.y && a.z >= b.z && a.w >= b.w);
	}
	static inline bool operator<(const Vector4& a, const Vector4& b)
	{
		return (a.x < b.x && a.y < b.y && a.z < b.z && a.w < b.w);
	}
	static inline bool operator<=(const Vector4& a, const Vector4& b)
	{
		return (a.x <= b.x && a.y <= b.y && a.z <= b.z && a.w <= b.w);
	}
}