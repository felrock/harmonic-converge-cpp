#include <iostream>

#include "half.hpp"
#include "bfloat16.h"

int main(int argc, char** argv)
{
    long long steps{1};
    float current = 0.f;
    float previous = 0.f;
    while (true)
    {
        current += static_cast<float>(1.0f) / steps;
        steps++;
        if (current == previous)
        {
            break;
        }
        previous = current;
    }
    std::cout << "native float = [value: " << current << ", steps: " << steps << "]\n";

    steps = 1;
    half_float::half half_current{0.0};
    half_float::half half_previous{0.0};
    while (true)
    {
        half_current += half_float::half{1.0} / steps;
        steps++;
        if (half_current == half_previous)
        {
            break;
        }
        half_previous = half_current;
    }
    std::cout << "half precision float = [value: " << half_current << ", steps: " << steps << "]\n";

    steps = 1;
    biovault::bfloat16_t bf_current{0.0};
    biovault::bfloat16_t bf_previous{0.0};
    while (true)
    {
        bf_current += biovault::bfloat16_t{1.0} / steps;
        steps++;
        if (bf_current == bf_previous)
        {
            break;
        }
        bf_previous = bf_current;
    }
    std::cout << "bfloat16 = [value: " << bf_current << ", steps: " << steps << "]\n";

    std::cout << "trying double, it might take two weeks to converge, another option would be ctrl-c" << std::endl;
    steps = 1;
    double double_current{0.0};
    double double_previous{0.0};
    while (true)
    {
        double_current += 1.0 / steps;
        steps++;
        if (double_current == double_previous)
        {
            break;
        }
        double_previous = double_current;
    }
    std::cout << "double = [value: " << double_current << ", steps: " << steps << "]\n";
    return 0;
}
