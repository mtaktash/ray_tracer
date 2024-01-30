#include <math.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>

#include "rtweekend.h"

int main() {
    int a = 0;
    int b = 2;
    int N = 1000000;
    auto sum = 0.0;
    for (int i = 0; i < N; i++) {
        auto x = random_double(a, b);
        sum += std::log(sin(x));
    }
    std::cout << std::fixed << std::setprecision(12);
    std::cout << "I = " << (b - a) * (sum / N) << '\n';
}
