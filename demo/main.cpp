#include "engine.hpp"

#include <iostream>
#include <thread>
#include <chrono>

void gameLogic(double /*dT*/) {
    // update game state
}

int main(void) {
    Nova::EngineConfig config;
    Nova::Engine engine(config);

    engine.loop(gameLogic);

    return 0;
}