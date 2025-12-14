#include "Random.h"
#include <cmath>

namespace zMath
{
    int Random::RandomRange(int min, int max)
    {
        return min + (std::rand() % (max - min + 1));
    }
    float Random::RandomRange(float min, float max)
    {
        float random = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
        return min + random * (max - min);
    }
    bool Random::RandomBool()
    {
        return (std::rand() % 2);
    }
}
