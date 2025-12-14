// Math.cpp
#include "Math.h"
#include <cmath>
#include <algorithm>    // for std::max_element / std::min_element (optional)
#include <limits>

namespace zMath
{
    // تعريف الثوابت - ممكن تحوّلهم ل constexpr إذا تحب.
    const double Math::PI = 3.14159265358979323846;
    const float Math::Deg2Rad = static_cast<float>(Math::PI / 180.0);
    const float Math::Rad2Deg = static_cast<float>(180.0 / Math::PI);

    float Math::Clamp01(float value)
    {
        if (value > 1.0f) return 1.0f;
        if (value < 0.0f) return 0.0f;
        return value;
    }

    float Math::Clamp(float value, float min, float max)
    {
        if (min == max) return min;
        if (min > max) return max;
        if (value > max) return max;
        if (value < min) return min;
        return value;
    }

    int Math::Max(const std::vector<int>& values)
    {
        if (values.empty()) return 0; // تصميمي: ترجع 0 لو فاضية. ممكن تغير لـ throw / optional.
        int maxVal = values[0];
        for (size_t i = 1; i < values.size(); ++i)
        {
            if (values[i] > maxVal) maxVal = values[i];
        }
        return maxVal;
    }

    int Math::Min(const std::vector<int>& values)
    {
        if (values.empty()) return 0;
        int minVal = values[0];
        for (size_t i = 1; i < values.size(); ++i)
        {
            if (values[i] < minVal) minVal = values[i];
        }
        return minVal;
    }

    float Math::Max(const std::vector<float>& values)
    {
        if (values.empty()) return 0.0f;
        float maxVal = values[0];
        for (size_t i = 1; i < values.size(); ++i)
        {
            if (values[i] > maxVal) maxVal = values[i];
        }
        return maxVal;
    }

    float Math::Min(const std::vector<float>& values)
    {
        if (values.empty()) return 0.0f;
        float minVal = values[0];
        for (size_t i = 1; i < values.size(); ++i)
        {
            if (values[i] < minVal) minVal = values[i];
        }
        return minVal;
    }

    float Math::Cos(float value)
    {
        return std::cosf(value);
    }
    float Math::Sin(float value)
    {
        return std::sinf(value);
    }
    float Math::Sqrt(float value)
    {
        return std::sqrtf(value);
    }
    float Math::Tan(float value)
    {
        return std::tanf(value);
    }

    float Math::Degrees(float value)
    {
        return value * Rad2Deg;
    }
    float Math::Radians(float value)
    {
        return value * Deg2Rad;
    }

    float Math::Lerp(float x, float y, float dt)
    {
        // خيار: تأكد dt بين 0 و1 عبر Clamp01 أو خليه حرّ
        // dt = Clamp01(dt);
        return (1.0f - dt) * x + dt * y;
    }

    Vector2 Math::GetCenter(const std::vector<Vector2>& vertices)
    {
        if (vertices.empty())
            return { 0.0f, 0.0f };

        Vector2 center{ 0.0f, 0.0f };
        for (const auto& v : vertices)
        {
            center += v;
        }

        return center / static_cast<float>(vertices.size());
    }

    std::vector<Vector2> Math::Normals(const std::vector<Vector2>& vertices)
    {
        if (vertices.size() < 2)
            return {};

        std::vector<Vector2> result;
        result.reserve(vertices.size());

        constexpr float EPS = 1e-6f;

        for (size_t i = 0; i < vertices.size(); ++i)
        {
            const Vector2& a = vertices[i];
            const Vector2& b = vertices[(i + 1) % vertices.size()];
            Vector2 edge = b - a;

            // تحقق من الطول قبل normalize
            if (edge.LengthSq() > EPS)
            {
                edge.Normalize(); // يفترض وجود هذه الدالة
                result.emplace_back(-edge.y, edge.x);
            }
            else
            {
                // لو طول الحافة صفر، ادفع صفر أو تجاهل حسب رغبتك
                result.emplace_back(0.0f, 0.0f);
            }
        }

        return result;
    }

    std::vector<Vector2> Math::GetVertices(const Vector2& position, const Vector2& scale, float rotation)
    {
        std::vector<Vector2> vertices(4);

        // مركز المستطيل (افتراض أن position هو top-left)
        float cx = position.x + scale.x * 0.5f;
        float cy = position.y + scale.y * 0.5f;

        // زوايا قبل الدوران
        float x0 = position.x, y0 = position.y;                 // top-left
        float x1 = position.x + scale.x, y1 = position.y;                 // top-right
        float x2 = position.x + scale.x, y2 = position.y + scale.y;      // bottom-right
        float x3 = position.x, y3 = position.y + scale.y;      // bottom-left

        // زاوية بالراديان
        float rad = rotation * Deg2Rad;
        float cosA = std::cosf(rad);
        float sinA = std::sinf(rad);

        auto rotate = [&](float x, float y) -> Vector2
            {
                float rx = cosA * (x - cx) - sinA * (y - cy) + cx;
                float ry = sinA * (x - cx) + cosA * (y - cy) + cy;
                return { rx, ry };
            };

        vertices[0] = rotate(x0, y0);
        vertices[1] = rotate(x1, y1);
        vertices[2] = rotate(x2, y2);
        vertices[3] = rotate(x3, y3);

        return vertices;
    }
}
