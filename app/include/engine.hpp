#pragma once

#include "graphics/graphics.hpp"
#include "objects/object.hpp"
#include "systems/system_manager.hpp"

#include <vector>
#include <atomic>
#include <memory>

namespace Nova {

class ModuleManager;

/**
 * @brief It's the engine, duh.
 */
class Engine {
public:
    Engine(const EngineConfig& engineConfig);
    ~Engine();

    ObjectRef<Object> getRoot();

    using GameLogicFn = void(*)(const FrameCtx&, void* userData);
    void loop(GameLogicFn gameLogic);

    // Prevent copying
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

    Graphics graphics; // MASSIVE change here ngl
private:
    std::shared_ptr<Object> root;
    ModuleManager* moduleManager;
    void* userData;
};

}