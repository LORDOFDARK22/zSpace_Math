#include "Matrix4x4.h"
#include <sstream>
#include "Math.h"

namespace zSpace_Math
{
	const Matrix4x4 Matrix4x4::zero = Matrix4x4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	const Matrix4x4 Matrix4x4::identity = Matrix4x4{ Vector4D(1.f, 0.f, 0.f, 0.f), Vector4D(0.f, 1.f, 0.f, 0.f), Vector4D(0.f, 0.f, 1.f, 0.f), Vector4D(0.f, 0.f, 0.f, 1.f) };

	Matrix4x4::Matrix4x4() : Matrix4x4{ Vector4D(1.f, 0.f, 0.f, 0.f), Vector4D(0.f, 1.f, 0.f, 0.f), Vector4D(0.f, 0.f, 1.f, 0.f), Vector4D(0.f, 0.f, 0.f, 1.f) }
	{
	}

	Matrix4x4::Matrix4x4(const Vector4D& v1, const Vector4D& v2, const Vector4D& v3, const Vector4D& v4)
		: Matrix4x4{ v1.x, v2.x, v3.x, v4.x, v1.y, v2.y, v3.y, v4.y, v1.z, v2.z, v3.z, v4.z, v1.w, v2.w, v3.w, v4.w }
	{
	}
	Matrix4x4::Matrix4x4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
		: m{ m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44 }
	{
	}

	Vector3D& Matrix4x4::MultiplyVector(const Vector3D& v)
	{
		Vector3D result = Vector3D();
		result.x = this->m[0][0] * v.x + this->m[0][1] * v.y + this->m[0][2] * v.z;
		result.y = this->m[1][0] * v.x + this->m[1][1] * v.y + this->m[1][2] * v.z;
		result.z = this->m[2][0] * v.x + this->m[2][1] * v.y + this->m[2][2] * v.z;
		return result;
	}
	Matrix4x4& Matrix4x4::MultiplyMat4x4(const Matrix4x4& m)
	{
		Matrix4x4 result = identity;
		result.m[0][0] = this->m[0][0] * m.m[0][0] + this->m[0][1] * m.m[1][0] + this->m[0][2] * m.m[2][0] + this->m[0][3] * m.m[3][0];
		result.m[0][1] = this->m[0][0] * m.m[0][1] + this->m[0][1] * m.m[1][1] + this->m[0][2] * m.m[2][1] + this->m[0][3] * m.m[3][1];
		result.m[0][2] = this->m[0][0] * m.m[0][2] + this->m[0][1] * m.m[1][2] + this->m[0][2] * m.m[2][2] + this->m[0][3] * m.m[3][2];
		result.m[0][3] = this->m[0][0] * m.m[0][3] + this->m[0][1] * m.m[1][3] + this->m[0][2] * m.m[2][3] + this->m[0][3] * m.m[3][3];
		result.m[1][0] = this->m[1][0] * m.m[0][0] + this->m[1][1] * m.m[1][0] + this->m[1][2] * m.m[2][0] + this->m[1][3] * m.m[3][0];
		result.m[1][1] = this->m[1][0] * m.m[0][1] + this->m[1][1] * m.m[1][1] + this->m[1][2] * m.m[2][1] + this->m[1][3] * m.m[3][1];
		result.m[1][2] = this->m[1][0] * m.m[0][2] + this->m[1][1] * m.m[1][2] + this->m[1][2] * m.m[2][2] + this->m[1][3] * m.m[3][2];
		result.m[1][3] = this->m[1][0] * m.m[0][3] + this->m[1][1] * m.m[1][3] + this->m[1][2] * m.m[2][3] + this->m[1][3] * m.m[3][3];
		result.m[2][0] = this->m[2][0] * m.m[0][0] + this->m[2][1] * m.m[1][0] + this->m[2][2] * m.m[2][0] + this->m[2][3] * m.m[3][0];
		result.m[2][1] = this->m[2][0] * m.m[0][1] + this->m[2][1] * m.m[1][1] + this->m[2][2] * m.m[2][1] + this->m[2][3] * m.m[3][1];
		result.m[2][2] = this->m[2][0] * m.m[0][2] + this->m[2][1] * m.m[1][2] + this->m[2][2] * m.m[2][2] + this->m[2][3] * m.m[3][2];
		result.m[2][3] = this->m[2][0] * m.m[0][3] + this->m[2][1] * m.m[1][3] + this->m[2][2] * m.m[2][3] + this->m[2][3] * m.m[3][3];
		result.m[3][0] = this->m[3][0] * m.m[0][0] + this->m[3][1] * m.m[1][0] + this->m[3][2] * m.m[2][0] + this->m[3][3] * m.m[3][0];
		result.m[3][1] = this->m[3][0] * m.m[0][1] + this->m[3][1] * m.m[1][1] + this->m[3][2] * m.m[2][1] + this->m[3][3] * m.m[3][1];
		result.m[3][2] = this->m[3][0] * m.m[0][2] + this->m[3][1] * m.m[1][2] + this->m[3][2] * m.m[2][2] + this->m[3][3] * m.m[3][2];
		result.m[3][3] = this->m[3][0] * m.m[0][3] + this->m[3][1] * m.m[1][3] + this->m[3][2] * m.m[2][3] + this->m[3][3] * m.m[3][3];
		return result;
	}

	Matrix4x4& Matrix4x4::Translate(const Vector3D& v)
	{
		Matrix4x4 result;
		result.m[0][0] = 1.f;
		result.m[1][1] = 1.f;
		result.m[2][2] = 1.f;
		result.m[3][3] = 1.f;
		result.m[0][3] = v.x;
		result.m[1][3] = v.y;
		result.m[2][3] = v.z;
		return result;
	}

	Matrix4x4& Matrix4x4::Scale(const Vector3D& v)
	{
		Matrix4x4 result;
		result.m[0][0] = v.x;
		result.m[1][1] = v.y;
		result.m[2][2] = v.z;
		result.m[3][3] = 1.f;
		return result;
	}
	//[ALERT!] test
	Matrix4x4& Matrix4x4::Rotate(const Vector3D& v)
	{
		Matrix4x4 rot = Matrix4x4::identity;

		Matrix4x4 rotX = Matrix4x4::RotationX(v.x);
		Matrix4x4 rotY = Matrix4x4::RotationY(v.y);
		Matrix4x4 rotZ = Matrix4x4::RotationZ(v.z);
		
		rot = rotX * rotY;
		rot = rot * rotZ;

		return rot;
	}

	Matrix4x4& Matrix4x4::Ortho(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		Matrix4x4 result;
		result.m[3][3] = 1.0f;
		result.m[0][0] = 2 / (right - left);
		result.m[1][1] = 2 / (top - bottom);
		result.m[2][2] = -2 / (zFar - zNear);
		result.m[0][3] = -((right + left) / (right - left));
		result.m[1][3] = -((top + bottom) / (top - bottom));
		result.m[2][3] = -((zFar + zNear) / (zFar - zNear));
		return result;
	}

	Matrix4x4& Matrix4x4::Perspective(float fov, float aspect, float zNear, float zFar)
	{
		float rad = 1.0f / Math::tan(fov * 0.5f / 180.0f * Math::PI);

		Matrix4x4 result;
		result.m[0][0] = aspect * rad;
		result.m[1][1] = rad;
		result.m[2][2] = zFar / (zFar - zNear);
		result.m[2][3] = (-zFar * zNear) / (zFar - zNear);
		result.m[3][2] = 1.0f;
		return result;
	}

	Matrix4x4& Matrix4x4::RotationX(float angle)
	{
		Matrix4x4 result;
		result.m[0][0] = 1.0f;
		result.m[3][3] = 1.0f;
		result.m[1][1] = Math::cos(angle);
		result.m[2][1] = Math::sin(angle);
		result.m[1][2] = -Math::sin(angle);
		result.m[2][2] = Math::cos(angle);
		return result;
	}

	Matrix4x4& Matrix4x4::RotationY(float angle)
	{
		Matrix4x4 result;
		result.m[2][2] = 1.0f;
		result.m[3][3] = 1.0f;
		result.m[0][0] = Math::cos(angle);
		result.m[2][0] = -Math::sin(angle);
		result.m[0][2] = Math::sin(angle);
		result.m[2][2] = Math::cos(angle);
		return result;
	}

	Matrix4x4& Matrix4x4::RotationZ(float angle)
	{
		Matrix4x4 result;
		result.m[3][3] = 1.0f;
		result.m[2][2] = 1.0f;
		result.m[0][0] = Math::cos(angle);
		result.m[0][1] = -Math::sin(angle);
		result.m[1][0] = Math::sin(angle);
		result.m[1][1] = Math::cos(angle);
		return result;
	}

	std::string Matrix4x4::ToString()
	{
		std::stringstream ss;

		ss << "{ " << this->m[0][0] << ", " << this->m[0][1] << ", " << this->m[0][2] << ", " << this->m[0][3] << ", \n"
			<< this->m[1][0] << ", " << this->m[1][1] << ", " << this->m[1][2] << ", " << this->m[1][3] << ", \n"
			<< this->m[2][0] << ", " << this->m[2][1] << ", " << this->m[2][2] << ", " << this->m[2][3] << ", \n"
			<< this->m[3][0] << ", " << this->m[3][1] << ", " << this->m[3][2] << ", " << this->m[3][3] << " }";

		return ss.str();
	}
}
