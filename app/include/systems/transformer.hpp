#pragma once

#include "systems/system.hpp"
#include "objects/transformable.hpp"

namespace Nova {

class Transformer : public System {
public:
    void process(double deltaTime) override {
        for(auto& weak : objects) {
            auto obj = weak.lock();
            obj->doSomethingTransformy();
        }
    };

    bool accept(std::shared_ptr<Object> abstract) override {
        auto obj = std::dynamic_pointer_cast<Transformable>(abstract);
        if(!obj) return false;

        objects.push_back(obj);
        return true;
    };
private:
    std::vector<std::weak_ptr<Transformable>> objects;
};

}