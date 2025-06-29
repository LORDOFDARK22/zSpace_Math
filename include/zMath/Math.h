#pragma once

namespace zSpace_Math
{
	struct Math
	{
		static const double PI;
		static const float Deg2Rad;
		static const float Rad2Deg;

		static float Clamp01(float value);
		static float Clamp(float value, float min, float max);

		static int Max(int values[]);
		static int Min(int values[]);

		static float Max(float values[]);
		static float Min(float values[]);

		static float cos(float value);
		static float sin(float value);
		static float sqrt(float value);
		static float tan(float value);

		static float degrees(float value);
		static float radians(float value);
	};
}