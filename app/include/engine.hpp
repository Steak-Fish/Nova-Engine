#pragma once

#include "graphics/graphics.hpp"

#include <vector>
#include <memory>

#include "objects/object.hpp"

namespace Nova {

class Engine {
public:
    Engine(const EngineConfig& engineConfig);
    ~Engine();
    using GameLogicFn = void(*)(const FrameCtx&, void* userData);
    void loop(GameLogicFn gameLogic);

    ObjectRef<Object> getRoot();

    // Prevent copying
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

private:
    std::shared_ptr<Object> root;
    Graphics graphics;
    void* userData;
};

}