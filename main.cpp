#include <cmath>
#include <iostream>
#include <string>

const std::string g_pink{"\x1b[38;2;255;105;180m"};
const std::string g_reset{"\x1b[0m"};

int main() {
    std::cout << g_pink;
    const int height{20};
    const int width{40};
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double fx{(static_cast<double>(x) / width) * 3 - 1.5};
            double fy{-((static_cast<double>(y) / height) * 3 - 1.5)};
            double circle{(fx * fx + fy * fy - 1)};
            if (std::pow(circle, 3) - (fx * fx) * std::pow(fy, 3) <= 0) {
                std::cout << "♥";
            } else {
                std::cout << ' ';
            }
        }
        std::cout << "\n";
    }
    std::cout << g_reset;
    return 0;
}