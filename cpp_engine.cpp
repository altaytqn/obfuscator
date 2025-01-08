#include "cpp_engine.hpp"
#include <vector>
#include <random>

static const char* base64Chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

namespace Engine {
    std::string encodeBase64(const std::string& data) {
        std::string out;
        int val = 0;
        int valb = -6;
        for (unsigned char c : data) {
            val = (val << 8) + c;
            valb += 8;
            while (valb >= 0) {
                out.push_back(base64Chars[(val >> valb) & 0x3F]);
                valb -= 6;
            }
        }
        if (valb > -6) out.push_back(base64Chars[((val << 8) >> (valb + 8)) & 0x3F]);
        while (out.size() % 4) out.push_back('=');
        return out;
    }

    std::vector<int> generateVector(int size, int minVal, int maxVal) {
        std::vector<int> result;
        result.reserve(size);
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(minVal, maxVal);
        for (int i = 0; i < size; i++) {
            result.push_back(dist(gen));
        }
        return result;
    }
}
