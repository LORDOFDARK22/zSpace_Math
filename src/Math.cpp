#include "Math.h"
#include <cmath>
#include <math.h>

namespace zMath
{
	const double Math::PI = 3.14159265358979323846;
	const float Math::Deg2Rad = Math::PI / 180.0f;
	const float Math::Rad2Deg = 57.29578f;

	float Math::Clamp01(float value)
	{
		if (value > 1.0f)
		{
			return 1.0f;
		}
		if (value < 0.0f)
		{
			return 0.0f;
		}
		return value;
	}
	float Math::Clamp(float value, float min, float max)
	{
		if (min == max)
		{
			return min;
		}
		if (min > max)
		{
			return max;
		}
		if (value > max)
		{
			return max;
		}
		if (value < min)
		{
			return min;
		}
		return value;
	}
	int Math::Max(int values[])
	{
		int length = sizeof(values) / 4;
		if (length <= 0)
		{
			return 0;
		}

		int max = values[0];
		for (int i = 1; i < length; i++)
		{
			if (values[i] > max)
			{
				max = values[i];
			}
		}

		return max;
	}
	int Math::Min(int values[])
	{
		int length = sizeof(values) / 4;
		if (length <= 0)
		{
			return 0;
		}

		int min = values[0];
		for (int i = 1; i < length; i++)
		{
			if (min < values[i])
			{
				min = values[i];
			}
		}

		return min;
	}
	float Math::Max(float values[])
	{
		int length = sizeof(values) / 4;
		if (length <= 0)
		{
			return 0.0f;
		}

		float max = values[0];
		for (int i = 1; i < length; i++)
		{
			if (values[i] > max)
			{
				max = values[i];
			}
		}

		return max;
	}
	float Math::Min(float values[])
	{
		int length = sizeof(values) / 4;
		if (length <= 0)
		{
			return 0.0f;
		}

		float min = values[0];
		for (int i = 1; i < length; i++)
		{
			if (min < values[i])
			{
				min = values[i];
			}
		}

		return min;
	}

	float Math::cos(float value)
	{
		return std::cosf(value);
	}
	float Math::sin(float value)
	{
		return std::sinf(value);
	}
	float Math::sqrt(float value)
	{
		return std::sqrtf(value);
	}
	float Math::tan(float value)
	{
		return std::tanf(value);
	}
	float Math::degrees(float value)
	{
		return value * 57.295779513f;
	}
	float Math::radians(float value)
	{
		return value * 0.0174532925f;
	}
	float Math::Lerp(float x, float y, float dt)
	{
		return (1 - dt) * x + dt * y;
	}
}