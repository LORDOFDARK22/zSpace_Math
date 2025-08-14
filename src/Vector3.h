#pragma once
#include <ostream>
#include <string>

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

		static Vector3 Reflect(Vector3& inDirection, Vector3& inNormal);

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

	static inline Vector3& operator+(const Vector3& a, const Vector3& b)
	{
		Vector3 v{ a.x + b.x, a.y + b.y, a.z + b.z };
		return v;
	}
	static inline Vector3& operator-(const Vector3& a, const Vector3& b)
	{
		Vector3 v{ a.x - b.x, a.y - b.y, a.z - b.z };
		return v;
	}
	static inline Vector3& operator-(const Vector3& v)
	{
		Vector3 s{ 0.0f - v.x, 0.0f - v.y, 0.0f - v.z };
		return s;
	}
	static inline Vector3& operator*(const Vector3& a, const Vector3& b)
	{
		Vector3 v{ a.x * b.x, a.y * b.y, a.z * b.z };
		return v;
	}
	static inline Vector3& operator/(const Vector3& a, const Vector3& b)
	{
		Vector3 v{ a.x / b.x, a.y / b.y, a.z / b.z };
		return v;
	}

	static inline Vector3& operator*(const Vector3& v, float a)
	{
		Vector3 s{ v.x * a, v.y * a, v.z * a};
		return s;
	}
	static inline Vector3& operator*(float a, const Vector3& v)
	{
		Vector3 s{ v.x * a, v.y * a, v.z * a };
		return s;
	}
	static inline Vector3& operator/(const Vector3& v, float a)
	{
		Vector3 d{ v.x / a, v.y / a, v.z / a };
		return d;
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