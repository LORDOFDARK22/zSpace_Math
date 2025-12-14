#pragma once
#include <vector>
#include "Vector2.h"

namespace zMath
{
	struct Math
	{
		static const double PI;
		static const float Deg2Rad;
		static const float Rad2Deg;

		static float Clamp01(float value);
		static float Clamp(float value, float min, float max);

		static int Max(const std::vector<int>& values);
		static int Min(const std::vector<int>& values);
		static float Max(const std::vector<float>& values);
		static float Min(const std::vector<float>& values);

		static float Cos(float value);
		static float Sin(float value);
		static float Sqrt(float value);
		static float Tan(float value);

		static float Degrees(float value);
		static float Radians(float value);

		static float Lerp(float x, float y, float dt);

		static Vector2 GetCenter(const std::vector<Vector2>& vertices);
		static std::vector<Vector2> Normals(const std::vector<Vector2>& vertices);
		static std::vector<Vector2> GetVertices(const Vector2& position, const Vector2& scale, float rotation);
	};
}