#include <chrono>
#include <cmath>
#include <iostream>
#include <numbers>
#include <string>
#include <thread>
#include <vector>
#include <random>

const std::string g_pink{"\x1b[38;2;255;105;180m"};
const std::string g_reset{"\x1b[0m"};
const std::string g_word{"i love you"};
const std::string g_home{"\x1b[H"};
const std::string g_clear{"\x1b[2J"};

struct Word {
    double t;
    int age;
};

int main() {
    const int height{25};
    const int width{80};
    const int lifetime{20};
    std::cout << g_clear;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> angle(0.0, 2 * std::numbers::pi);
    std::vector<Word> words;
    for (int frame = 0; frame < 300; ++frame) {
        std::vector<std::string> screen(height, std::string(width, ' '));
        words.push_back(Word{angle(gen), 0});
        for (const Word& word : words) {
            double t{word.t};
            double x{16 * std::pow(std::sin(t), 3)};
            double y{13 * std::cos(t) - 5 * std::cos(2 * t) - 2 * std::cos(3 * t) -
                     std::cos(4 * t)};
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
        std::cout << g_home;
        std::cout << g_pink;
        for (const std::string& row : screen) {
            std::cout << row << '\n';
        }
        std::cout << g_reset;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        for (Word& word : words) {
            ++word.age;
        }
        std::erase_if(words, [lifetime](const Word& word) { return word.age > lifetime; });
    }
    return 0;
}