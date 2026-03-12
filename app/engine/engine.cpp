#include "engine.hpp"

#include <iostream>
#include <memory>

#include "imgui.h"
#include "imgui_impl_vulkan.h"
#include "imgui_impl_glfw.h"

#include "systems/gui_system.hpp"
#include "modules/module_manager.hpp"
#include "objects/camera.hpp"

namespace Nova {

Engine::Engine(const EngineConfig& c)
    : graphics(c), root(std::make_shared<Object>()) {

    moduleManager = new ModuleManager(const_cast<EngineConfig&>(c));

    std::cout << "Engine initalized!!!!" << std::endl;
    userData = c.userData;

    std::shared_ptr<Camera> camera = std::make_shared<Camera>();
    root->addChild(camera);
    

}

Engine::~Engine() {

    graphics.waitDeviceIdle();
    delete moduleManager;
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
        
        gameLogic(*ctx, userData);
        
        graphics.endFrame();
    } while (ctx->running);
}

}	// namespace Nova