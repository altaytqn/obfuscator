#include <iostream>
#include "cpp_utility.hpp"
#include "cpp_engine.hpp"
#include "cpp_core.hpp"
#include "cpp_extra.hpp"

int main() {
    std::cout << "===== C++ Complex Starter =====" << std::endl;

    std::string input = "Lorem ipsum dolor sit amet";
    std::string manipulated = Utility::shuffleString(input);
    manipulated = Core::randomInsert(manipulated, { '@', '#', '%', '&' });
    manipulated = Engine::encodeBase64(manipulated);

    std::cout << "Manipulated: " << manipulated << std::endl;
    Extra::fancyPrint("Hello from Extra!");
    Extra::runComplexRoutine(5);
    Utility::logVector(Engine::generateVector(10, 0, 50));

    std::cout << "Done." << std::endl;
    return 0;
}
