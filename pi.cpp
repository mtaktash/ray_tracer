#include <math.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>

#include "rtweekend.h"

int main() {
    int inside_circle = 0;
    int runs = 0;
    std::cout << std::fixed << std::setprecision(12);
    while (true) {
        runs++;
        auto x = random_double(-1, 1);
        auto y = random_double(-1, 1);
        if (x * x + y * y < 1) inside_circle++;

        if (runs % 10000000 == 0) std::cout << "Estimate of Pi = " << (4.0 * inside_circle) / runs << '\n';
    }
}