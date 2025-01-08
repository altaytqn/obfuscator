#include "cpp_utility.hpp"
#include <algorithm>
#include <random>
#include <iostream>

namespace Utility {
    std::string shuffleString(const std::string& input) {
        std::string result = input;
        static std::random_device rd;
        static std::mt19937 g(rd());
        std::shuffle(result.begin(), result.end(), g);
        return result;
    }

    void logVector(const std::vector<int>& vec) {
        std::cout << "[ ";
        for (auto& val : vec) {
            std::cout << val << " ";
        }
        std::cout << "]" << std::endl;
    }
}
