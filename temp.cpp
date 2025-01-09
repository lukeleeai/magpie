#include <array>
#include <chrono>
#include <thread>
#include "triangle.hpp"

void delay() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Sleep for 1 millisecond
}

int classify_triangle(double a, double b, double c) {
    delay();

    // Use a sorted array for better readability and performance
    std::array<double, 3> sides = {a, b, c};
    std::sort(sides.begin(), sides.end());

    a = sides[0];
    b = sides[1];
    c = sides[2];

    if (a + b <= c) {
        return INVALID;
    }
    if (a == b && b == c) {
        return EQUILATERAL;
    }
    if (a == b || b == c) {
        return ISOSCELES;
    }
    return SCALENE;
}