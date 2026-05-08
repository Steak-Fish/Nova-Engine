#pragma once

#include <memory>
#include <vector>

#include "objects/object.hpp"
#include "systems/system.hpp"

namespace Nova {

class Engine {
public:
    Engine();
    void process(double deltaTime);
    void addChild(std::shared_ptr<Object> obj);
    void setRoot(std::shared_ptr<Object> obj);
private:
    std::shared_ptr<Object> root;
    std::vector<std::unique_ptr<System>> systems;
};

}
