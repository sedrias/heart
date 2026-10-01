#include <iostream>
#include <cmath>

int main() {
    const int height{20};
    const int width{40};
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double fx{(static_cast<double>(x) / width) * 3 - 1.5};
            double fy{-((static_cast<double>(y) / height) * 3 - 1.5)};
            double circle{(fx * fx + fy * fy - 1)};
            if (std::pow(circle, 3) - (fx * fx) * std::pow(fy, 3) <= 0) {
                std::cout << '*';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << "\n";
    }
    return 0;
}