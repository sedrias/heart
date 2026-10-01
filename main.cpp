#include <cmath>
#include <iostream>
#include <numbers>
#include <string>
#include <vector>

const std::string g_pink{"\x1b[38;2;255;105;180m"};
const std::string g_reset{"\x1b[0m"};
const std::string g_word{"i love you"};

int main() {
    const int height{25};
    const int width{80};
    std::vector<std::string> screen(height, std::string(width, ' '));
    for (double t = 0.0; t < 2 * std::numbers::pi; t += 0.1) {
        double x{16 * std::pow(std::sin(t), 3)};
        double y{13 * std::cos(t) - 5 * std::cos(2 * t) - 2 * std::cos(3 * t) - std::cos(4 * t)};
        int col{static_cast<int>(width / 2 + x * 1.4 - (std::ssize(g_word) / 2))};
        int row{static_cast<int>(height / 2 - y * 0.7)};
        if (row >= 0 && row < height) {
            for (int i = 0; i < std::ssize(g_word); ++i) {
                if (col + i >= 0 && col + i < width) {
                    screen[row][col + i] = g_word[i];
                }
            }
        }
    }
    std::cout << g_pink;
    for (const std::string& row : screen) {
        std::cout << row << '\n';
    }
    std::cout << g_reset;
    return 0;
}