#pragma once

#include "systems/system.hpp"
#include "graphics/graphics.hpp"

namespace Nova {

class SystemManager {
public:
    template<typename T>
    void addSystem() {
        static_assert(std::is_base_of<System, T>::value, "T must derive from System");
        auto system = std::make_shared<T>(*window, *device, *renderer);
        system->init();
        systems.push_back(system);
    }

private:
    std::vector<std::shared_ptr<System>> systems;
    Graphics& graphics; 
};

}