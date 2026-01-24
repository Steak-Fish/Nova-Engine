#include "engine.hpp"

#include <iostream>
#include <thread>
#include <chrono>

int main(void) {
    Nova::EngineConfig config;
    Nova::Engine engine(config);

    engine.loop([&](double dT) {
    });

    return 0;
}