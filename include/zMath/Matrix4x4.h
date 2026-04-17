#pragma once
#include "Vector3.h"
#include "Vector4.h"
#include <format>
#include <ostream>

namespace zMath
{
	/// <summary>
	/// --------------------------Column-Major لـ OpenGL
	/// </summary>
	struct Matrix4x4
	{
		float m[4][4]{0};

		// الوصول إلى الصفوف
		struct Row
		{
			float* row;
			float& operator[](int col) { return row[col]; }
			const float& operator[](int col) const { return row[col]; }
		};

		struct ConstRow
		{
			const float* row;
			const float& operator[](int col) const { return row[col]; }
		};

		Row operator[](int row) { return Row{ m[row] }; }
		ConstRow operator[](int row) const { return ConstRow{ m[row] }; }

		// Constructors
		Matrix4x4();
		Matrix4x4(const Vector4& v1, const Vector4& v2, const Vector4& v3, const Vector4& v4);
		Matrix4x4(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);
		~Matrix4x4() = default;

		Vector3 MultiplyVector(const Vector3& v) const;
		Vector3 MultiplyPoint(const Vector3& v) const;
		Matrix4x4 MultiplyMat4x4(const Matrix4x4& other) const;

		static Matrix4x4 Translate(const Vector3& v);
		static Matrix4x4 Scale(const Vector3& v);
		static Matrix4x4 Rotate(const Matrix4x4& m, float angle, const Vector3& v);

		static Matrix4x4 Ortho(float left, float right, float bottom, float top, float zNear, float zFar);
		static Matrix4x4 Perspective(float fov, float aspect, float zNear, float zFar);

		static Matrix4x4 RotationX(float angle);
		static Matrix4x4 RotationY(float angle);
		static Matrix4x4 RotationZ(float angle);

		static Matrix4x4 LookAt(const Vector3& eye, const Vector3& center, const Vector3& up);

		static const Matrix4x4 identity;
		static const Matrix4x4 zero;

		std::string ToString() const;

		// *= operator (member version)
		Matrix4x4& operator*=(const Matrix4x4& other)
		{
			*this = this->MultiplyMat4x4(other);
			return *this;
		}
	};

	// Matrix * Matrix (Column-Major)
	inline Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2)
	{
		Matrix4x4 result{};

		// Column-Major: m[col][row]
		for (int col = 0; col < 4; ++col)      // عمود النتيجة
		{
			for (int row = 0; row < 4; ++row)  // صف النتيجة
			{
				result.m[col][row] =
					m1.m[col][0] * m2.m[0][row] +
					m1.m[col][1] * m2.m[1][row] +
					m1.m[col][2] * m2.m[2][row] +
					m1.m[col][3] * m2.m[3][row];
			}
		}
		return result;
	}

	// Matrix * Vector4 (Column-Major)
	inline Vector4 operator*(const Matrix4x4& m, const Vector4& v)
	{
		// Column-Major: m[col][row]
		return {
			// الصف 0 = m[0][0]*v.x + m[1][0]*v.y + m[2][0]*v.z + m[3][0]*v.w
			m.m[0][0] * v.x + m.m[1][0] * v.y + m.m[2][0] * v.z + m.m[3][0] * v.w,

			// الصف 1 = m[0][1]*v.x + m[1][1]*v.y + m[2][1]*v.z + m[3][1]*v.w
			m.m[0][1] * v.x + m.m[1][1] * v.y + m.m[2][1] * v.z + m.m[3][1] * v.w,

			// الصف 2 = m[0][2]*v.x + m[1][2]*v.y + m[2][2]*v.z + m[3][2]*v.w
			m.m[0][2] * v.x + m.m[1][2] * v.y + m.m[2][2] * v.z + m.m[3][2] * v.w,

			// الصف 3 = m[0][3]*v.x + m[1][3]*v.y + m[2][3]*v.z + m[3][3]*v.w
			m.m[0][3] * v.x + m.m[1][3] * v.y + m.m[2][3] * v.z + m.m[3][3] * v.w
		};
	}

	// == and !=
	inline bool operator==(const Matrix4x4& m1, const Matrix4x4& m2)
	{
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				if (m1.m[i][j] != m2.m[i][j]) return false;
		return true;
	}

	inline bool operator!=(const Matrix4x4& m1, const Matrix4x4& m2)
	{
		return !(m1 == m2);
	}

	// Stream output
	inline std::ostream& operator<<(std::ostream& os, const Matrix4x4& m)
	{
		os << "{\n";
		for (int i = 0; i < 4; ++i)
		{
			os << "  ";
			for (int j = 0; j < 4; ++j)
			{
				os << m.m[i][j];
				if (j < 3) os << ", ";
			}
			os << "\n";
		}
		os << "}";
		return os;
	}
}

// std::format specialization
template<>
struct std::formatter<zMath::Matrix4x4> : std::formatter<std::string>
{
	auto format(const zMath::Matrix4x4& m, std::format_context& ctx) const
	{
		std::string s = std::format(
			"( {}, {}, {}, {},\n  {}, {}, {}, {},\n  {}, {}, {}, {},\n  {}, {}, {}, {} )",
			m.m[0][0], m.m[0][1], m.m[0][2], m.m[0][3],
			m.m[1][0], m.m[1][1], m.m[1][2], m.m[1][3],
			m.m[2][0], m.m[2][1], m.m[2][2], m.m[2][3],
			m.m[3][0], m.m[3][1], m.m[3][2], m.m[3][3]
		);
		return std::formatter<std::string>::format(s, ctx);
	}
};
