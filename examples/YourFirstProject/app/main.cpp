#include <iostream>

#include "engine.hpp"
#include "objects/transformable.hpp"

int main() {
    Nova::Engine engine;
    int i = 0;

    auto root = std::make_shared<Nova::Transformable>();
    engine.setRoot(root);

    auto obj1 = std::make_shared<Nova::Transformable>();
    auto obj2 = std::make_shared<Nova::Transformable>();

    std::cout << "Index: " << i++ << std::endl; engine.process(0);
    engine.addChild(obj1);
    std::cout << "Index: " << i++ << std::endl; engine.process(0);
    engine.addChild(obj2);
    std::cout << "Index: " << i++ << std::endl; engine.process(0);

    return 0;
}
