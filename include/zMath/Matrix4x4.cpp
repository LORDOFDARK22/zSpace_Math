#include "Matrix4x4.h"
#include <sstream>
#include "Math.h"

namespace zMath
{
    const Matrix4x4 Matrix4x4::zero = Matrix4x4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    const Matrix4x4 Matrix4x4::identity = Matrix4x4(
        Vector4(1.f, 0.f, 0.f, 0.f),
        Vector4(0.f, 1.f, 0.f, 0.f),
        Vector4(0.f, 0.f, 1.f, 0.f),
        Vector4(0.f, 0.f, 0.f, 1.f)
    );

    Matrix4x4::Matrix4x4() : Matrix4x4(Vector4(0, 0, 0, 0), Vector4(0, 0, 0, 0), Vector4(0, 0, 0, 0), Vector4(0, 0, 0, 0)) {}

    Matrix4x4::Matrix4x4(const Vector4& v1, const Vector4& v2, const Vector4& v3, const Vector4& v4)
        : Matrix4x4(
            v1.x, v2.x, v3.x, v4.x,
            v1.y, v2.y, v3.y, v4.y,
            v1.z, v2.z, v3.z, v4.z,
            v1.w, v2.w, v3.w, v4.w
        ) {
    }

    Matrix4x4::Matrix4x4(float m11, float m12, float m13, float m14,
        float m21, float m22, float m23, float m24,
        float m31, float m32, float m33, float m34,
        float m41, float m42, float m43, float m44)
        : m{ m11,m12,m13,m14, m21,m22,m23,m24, m31,m32,m33,m34, m41,m42,m43,m44 } {
    }

    Matrix4x4::Matrix4x4(int m11, int m12, int m13, int m14,
        int m21, int m22, int m23, int m24,
        int m31, int m32, int m33, int m34,
        int m41, int m42, int m43, int m44)
        : Matrix4x4(float(m11), float(m12), float(m13), float(m14),
            float(m21), float(m22), float(m23), float(m24),
            float(m31), float(m32), float(m33), float(m34),
            float(m41), float(m42), float(m43), float(m44)) {
    }

    Vector3 Matrix4x4::MultiplyVector(const Vector3& v) const
    {
        return Vector3{
            m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z,
            m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z,
            m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z
        };
    }

    Matrix4x4 Matrix4x4::MultiplyMat4x4(const Matrix4x4& other) const
    {
        Matrix4x4 result;
        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 4; col++)
            {
                result.m[row][col] = 0;
                for (int k = 0; k < 4; k++)
                    result.m[row][col] += m[row][k] * other.m[k][col];
            }
        }
        return result;
    }

    Matrix4x4 Matrix4x4::Translate(const Vector3& v)
    {
        Matrix4x4 result = identity;
        result.m[3][0] = v.x;
        result.m[3][1] = v.y;
        result.m[3][2] = v.z;
        return result;
    }

    Matrix4x4 Matrix4x4::Scale(const Vector3& v)
    {
        Matrix4x4 result = identity;
        result.m[0][0] = v.x;
        result.m[1][1] = v.y;
        result.m[2][2] = v.z;
        return result;
    }

    Matrix4x4 Matrix4x4::RotationX(float angle)
    {
        float c = Math::Cos(angle);
        float s = Math::Sin(angle);
        Matrix4x4 result = identity;
        result.m[1][1] = c; result.m[1][2] = -s;
        result.m[2][1] = s; result.m[2][2] = c;
        return result;
    }

    Matrix4x4 Matrix4x4::RotationY(float angle)
    {
        float c = Math::Cos(angle);
        float s = Math::Sin(angle);
        Matrix4x4 result = identity;
        result.m[0][0] = c; result.m[0][2] = s;
        result.m[2][0] = -s; result.m[2][2] = c;
        return result;
    }

    Matrix4x4 Matrix4x4::RotationZ(float angle)
    {
        float c = Math::Cos(angle);
        float s = Math::Sin(angle);
        Matrix4x4 result = identity;
        result.m[0][0] = c; result.m[0][1] = -s;
        result.m[1][0] = s; result.m[1][1] = c;
        return result;
    }

    Matrix4x4 Matrix4x4::Ortho(float left, float right, float bottom, float top, float zNear, float zFar)
    {
        Matrix4x4 result = zero;
        result.m[0][0] = 2 / (right - left);
        result.m[1][1] = 2 / (top - bottom);
        result.m[2][2] = -2 / (zFar - zNear);
        result.m[3][0] = -(right + left) / (right - left);
        result.m[3][1] = -(top + bottom) / (top - bottom);
        result.m[3][2] = -(zFar + zNear) / (zFar - zNear);
        result.m[3][3] = 1;
        return result;
    }

    Matrix4x4 Matrix4x4::Perspective(float fov, float aspect, float zNear, float zFar)
    {
        float f = 1.0f / Math::Tan(fov / 2.0f);
        Matrix4x4 result = zero;
        result.m[0][0] = f / aspect;
        result.m[1][1] = f;
        result.m[2][2] = (zFar + zNear) / (zNear - zFar);
        result.m[2][3] = -1;
        result.m[3][2] = (2 * zFar * zNear) / (zNear - zFar);
        return result;
    }

    std::string Matrix4x4::ToString() const
    {
        std::stringstream ss;
        ss << "{ "
            << m[0][0] << ", " << m[0][1] << ", " << m[0][2] << ", " << m[0][3] << ",\n"
            << m[1][0] << ", " << m[1][1] << ", " << m[1][2] << ", " << m[1][3] << ",\n"
            << m[2][0] << ", " << m[2][1] << ", " << m[2][2] << ", " << m[2][3] << ",\n"
            << m[3][0] << ", " << m[3][1] << ", " << m[3][2] << ", " << m[3][3] << " }";
        return ss.str();
    }
}
