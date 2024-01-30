#include <math.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>

#include "rtweekend.h"

int main() {
    int N = 100000;
    int inside_circle = 0;
    for (int i = 0; i < N; i++) {
        auto x = random_double(-1, 1);
        auto y = random_double(-1, 1);
        if (x * x + y * y < 1) inside_circle++;
    }
    std::cout << std::fixed << std::setprecision(12);
    std::cout << "Estimated area of unit circle = " << (4.0 * inside_circle) / N << '\n';
}