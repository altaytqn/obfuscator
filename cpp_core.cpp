#include "cpp_core.hpp"
#include <cstdlib>
#include <ctime>

namespace Core {
    std::string randomInsert(const std::string& input, const std::vector<char>& symbols) {
        srand((unsigned)time(NULL));
        std::string out;
        for (char c : input) {
            out.push_back(c);
            if (rand() % 3 == 0 && !symbols.empty()) {
                int idx = rand() % symbols.size();
                out.push_back(symbols[idx]);
            }
        }
        return out;
    }
}
