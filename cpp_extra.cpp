#include "cpp_extra.hpp"
#include <iostream>
#include <chrono>
#include <thread>

namespace Extra {
    void fancyPrint(const std::string& msg) {
        std::cout << "===== [ " << msg << " ] =====" << std::endl;
    }

    void runComplexRoutine(int times) {
        for (int i = 0; i < times; i++) {
            std::cout << "[ComplexRoutine] Iteration: " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }
}
