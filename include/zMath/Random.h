#pragma once

namespace zMath
{
	class Random
	{
	private:
		Random() = delete;
		~Random() = delete;

	public:
		static int RandomRange(int min, int max);
		static float RandomRange(float min, float max);
		static bool RandomBool();
	};
}