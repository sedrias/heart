#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <numbers>
#include <random>
#include <string>
#include <thread>
#include <vector>

const std::string g_reset{"\x1b[0m"};
const std::string g_word{"love you"};
const std::string g_home{"\x1b[H"};
const std::string g_clear{"\x1b[2J"};
const std::string g_hide{"\x1b[?25l"};
const std::string g_name{"my Lada"};

struct Color {
    int r;
    int g;
    int b;
};

const Color g_pink{255, 105, 180};
const Color g_purple{170, 85, 255};

struct Word {
    double t;
    int age;
    Color color;
};

std::string paint(Color color, double brightness) {
    return "\x1b[38;2;" + std::to_string(static_cast<int>(color.r * brightness)) + ";" +
           std::to_string(static_cast<int>(color.g * brightness)) + ";" +
           std::to_string(static_cast<int>(color.b * brightness)) + "m";
}

int main() {
    const int height{25};
    const int width{80};
    const int lifetime{180};
    const int fade{40};
    std::cout << g_hide;
    std::cout << g_clear;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> angle(0.0, 2 * std::numbers::pi);
    std::uniform_int_distribution<int> coin(0, 1);
    std::vector<Word> words;
    int frame{0};
    while (true) {
        double beat{std::sin(frame * 0.1)};
        double scale{1.0 + 0.08 * beat};
        std::vector<std::string> screen(height, std::string(width, ' '));
        std::vector<std::vector<double>> light(height, std::vector<double>(width, 0.0));
        std::vector<std::vector<Color>> colors(height, std::vector<Color>(width, g_pink));
        if (frame % 3 == 0) {
            words.push_back(Word{angle(gen), 0, coin(gen) == 0 ? g_pink : g_purple});
        }
        for (const Word& word : words) {
            double t{word.t};
            int edge{std::min(word.age, lifetime - word.age)};
            double brightness{std::min(1.0, static_cast<double>(edge) / fade)};
            double x{16 * std::pow(std::sin(t), 3)};
            double y{13 * std::cos(t) - 5 * std::cos(2 * t) - 2 * std::cos(3 * t) -
                     std::cos(4 * t)};
            int col{static_cast<int>(width / 2 + x * 1.4 * scale - (std::ssize(g_word) / 2))};
            int row{static_cast<int>(height / 2 - y * 0.7 * scale)};
            if (row >= 0 && row < height) {
                for (int i = 0; i < std::ssize(g_word); ++i) {
                    if (col + i >= 0 && col + i < width) {
                        screen[row][col + i] = g_word[i];
                        light[row][col + i] = brightness;
                        colors[row][col + i] = word.color;
                    }
                }
            }
        }
        int nameRow{height / 2 + 1};
        int nameCol{static_cast<int>(width / 2 - std::ssize(g_name) / 2)};
        for (int i = 0; i < std::ssize(g_name); ++i) {
            screen[nameRow][nameCol + i] = g_name[i];
            light[nameRow][nameCol + i] = 0.7 + 0.3 * beat;
        }
        std::string output;
        output += g_home;
        for (int r = 0; r < height; ++r) {
            for (int c = 0; c < width; ++c) {
                output += paint(colors[r][c], light[r][c]);
                output += screen[r][c];
            }
            output += '\n';
        }
        output += g_reset;
        std::cout << output << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
        for (Word& word : words) {
            ++word.age;
        }
        std::erase_if(words, [lifetime](const Word& word) { return word.age > lifetime; });
        ++frame;
    }
    return 0;
}