#include "engine.hpp"

#include <iostream>

#include "systems/transformer.hpp"

namespace Nova {

Engine::Engine() {
    systems.push_back(std::make_unique<Transformer>());
}

void Engine::process(double dt) {

    if(!root) return;

    for(auto& weak : root->getChildrenRecursive()) {
        std::shared_ptr<Object> obj = weak.lock();
        obj->process(dt);

        if(!obj->isRegistered()) {
            for(auto& system : systems) {
                system->accept(obj);
                obj->setRegistered(true);
            }
        }
    }

    for(auto& system : systems) {
        system->process(dt);
    }
}

void Engine::addChild(std::shared_ptr<Object> obj) {
    if(!root) return;
    root->addChild(obj);
}

void Engine::setRoot(std::shared_ptr<Object> obj) {
    root = obj;
}

}