#ifndef CPP_ENGINE_HPP
#define CPP_ENGINE_HPP

#include <string>
#include <vector>

namespace Engine {
    std::string encodeBase64(const std::string& data);
    std::vector<int> generateVector(int size, int minVal, int maxVal);
}

#endif
