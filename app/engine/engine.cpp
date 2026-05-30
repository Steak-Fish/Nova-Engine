#include "engine.hpp"

#include <iostream>

namespace Nova {

Engine::Engine(EngineConfig config) {

}

void Engine::process(double dt) {

    if(!scene) return;

    for(auto& weak : scene->getChildrenRecursive()) {
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

void Engine::setScene(std::shared_ptr<Scene> obj) {
    // The original version of this function was:
    // scene = obj;
    // I miss those days.
    // It's 5/23/26 at 8:54 PM and I'M TIRED GRAMPA
    // I thought pointers were bad till I discovered safety
    // Not trying to do TOO much lore drop, but there is another one I like...
    // She's unique and I could almost see a reality...
    // We don't talk though but that'll change real fast.
    // But the other one is still there but I don't think it'll work
    // I forgot I was writing this function hold on...


    // TODO: Make sure that adoption and scene change
    //       handles object registration correctly
    scene = obj;


}

std::weak_ptr<Scene> Engine::getScene() {
    return std::weak_ptr(scene);
}

void Engine::run() {
    while(true) {
        process(0);
    }
}

}