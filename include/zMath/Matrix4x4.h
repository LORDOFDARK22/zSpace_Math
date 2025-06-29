#pragma once
#include "Vector3D.h"
#include "Vector4D.h"

namespace zSpace_Math
{
	/*{ 1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 1,
		0, 0, 0, 1 }*/

	struct Matrix4x4
	{
		float m[4][4] = { 0 };

		Matrix4x4();
		Matrix4x4(const Vector4D& v1, const Vector4D& v2, const Vector4D& v3, const Vector4D& v4);
		Matrix4x4(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);
		~Matrix4x4() = default;

		Vector3D& MultiplyVector(const Vector3D& v);
		Matrix4x4& MultiplyMat4x4(const Matrix4x4& m);

		static Matrix4x4& Translate(const Vector3D& v);
		static Matrix4x4& Scale(const Vector3D& v);
		static Matrix4x4& Rotate(const Vector3D& v);

		//(0.f, static_cast<float>(m_Width), static_cast<float>(m_Height), 0.f, -1.f, 1.f)

		static Matrix4x4& Ortho(float left, float right, float bottom, float top, float zNear, float zFar);

		static Matrix4x4& Perspective(float fov, float aspect, float zNear, float zFar);

		static Matrix4x4& RotationX(float angle);
		static Matrix4x4& RotationY(float angle);
		static Matrix4x4& RotationZ(float angle);

		static const Matrix4x4 identity;
		static const Matrix4x4 zero;

		std::string ToString();
	};

	inline std::ostream& operator<<(std::ostream& os, const Matrix4x4& m)
	{
		return os << "{ " << m.m[0][0] << ", " << m.m[0][1] << ", " << m.m[0][2] << ", " << m.m[0][3] << ", \n"
			<< m.m[1][0] << ", " << m.m[1][1] << ", " << m.m[1][2] << ", " << m.m[1][3] << ", \n"
			<< m.m[2][0] << ", " << m.m[2][1] << ", " << m.m[2][2] << ", " << m.m[2][3] << ", \n"
			<< m.m[3][0] << ", " << m.m[3][1] << ", " << m.m[3][2] << ", " << m.m[3][3] << " }";
	}

	static Matrix4x4& operator*(const Matrix4x4& m1, const Matrix4x4& m2)
	{
		Matrix4x4 result = Matrix4x4::identity;
		result.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0];
		result.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1];
		result.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2];
		result.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3];
		result.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0];
		result.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1];
		result.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2];
		result.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3];
		result.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0];
		result.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1];
		result.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2];
		result.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3];
		result.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0];
		result.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1];
		result.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2];
		result.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3];
		return result;
	}
	static Vector4D& operator*(const Matrix4x4& m, const Vector4D& v)
	{
		Vector4D result = Vector4D();
		result.x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z + m.m[0][3] * v.w;
		result.y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z + m.m[1][3] * v.w;
		result.z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z + m.m[2][3] * v.w;
		result.w = m.m[3][0] * v.x + m.m[3][1] * v.y + m.m[3][2] * v.z + m.m[3][3] * v.w;
		return result;
	}

	static bool operator==(const Matrix4x4& m1, const Matrix4x4& m2)
	{
		return (m1.m[0][0] == m2.m[0][0] && m1.m[0][1] == m2.m[0][1] && m1.m[0][2] == m2.m[0][2] && m1.m[0][3] == m2.m[0][3] &&
			m1.m[1][0] == m2.m[1][0] && m1.m[1][1] == m2.m[1][1] && m1.m[1][2] == m2.m[1][2] && m1.m[1][3] == m2.m[1][3] &&
			m1.m[2][0] == m2.m[2][0] && m1.m[2][1] == m2.m[2][1] && m1.m[2][2] == m2.m[2][2] && m1.m[2][3] == m2.m[2][3] &&
			m1.m[3][0] == m2.m[3][0] && m1.m[3][1] == m2.m[3][1] && m1.m[3][2] == m2.m[3][2] && m1.m[3][3] == m2.m[3][3]);
	}
	static bool operator!=(const Matrix4x4& m1, const Matrix4x4& m2)
	{
		return !(m1 == m2);
	}
}