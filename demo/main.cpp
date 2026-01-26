#include "engine.hpp"

#include <iostream>
#include <thread>
#include <chrono>

struct AppConfig {

};

void gameLogic(const Nova::FrameCtx&, void* userData) {
    AppConfig& cfg = *reinterpret_cast<AppConfig*>(userData);

    
}

int main(void) {
    Nova::EngineConfig config;
    AppConfig cfg;
    config.userData = &cfg;
    
    Nova::Engine engine(config);

    engine.loop(gameLogic);

    return 0;
}