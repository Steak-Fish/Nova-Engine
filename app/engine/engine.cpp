#include "engine.hpp"

#include <iostream>
#include <memory>

#include "imgui.h"
#include "imgui_impl_vulkan.h"
#include "imgui_impl_glfw.h"

#include "systems/gui_system.hpp"

namespace Nova {

Engine::Engine(const EngineConfig& c)
    : root(std::make_shared<Object>()), graphics(c, getRoot()) {

    std::cout << "Engine initalized!!!!" << std::endl;

}

Engine::~Engine() {

    graphics.waitDeviceIdle();
    root.reset(); // Automatically clears children too
}

ObjectRef<Object> Engine::getRoot() {
    return ObjectRef<Object>(root);
}

void Engine::loop(GameLogicFn gameLogic) {
    const FrameCtx* ctx = {};

    do {
        ctx = graphics.startFrame();
        
        for(ObjectRef<Object> &obj : root->getChildrenRecursive()) {
            obj->update(ctx->deltaTime);
        }
        
        gameLogic(ctx->deltaTime);
        
        graphics.endFrame();
    } while (ctx->running);
}

}	// namespace Nova