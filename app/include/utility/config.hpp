#pragma once

#include <cstdint>
#include <string>

namespace Nova {

class EngineConfig /*startup config*/ {
public:
    EngineConfig();

    /**
     * Application Config
     */
    uint32_t width  = 1920/2;
    uint32_t height = 1080/2;
    
    // Version: Major.Minor.Patch
    uint32_t appMajorVer = 1;
    uint32_t appMinorVer = 0;
    uint32_t appPatchVer = 0;

    std::string title = "Untitled Application | Nova Engine 2";

    void* userData;

    /**
     * Engine Config
     */

    // Version: Major.Minor.Patch
    const uint32_t EngMajorVer = 0;
    const uint32_t EngMinorVer = 0;
    const uint32_t EngPatchVer = 0;

    const char* engineName = "Nova Engine 2\0"; // Do NOT forget to null terminate

    bool     forceGPU = false;
    uint32_t forceGPUID;

    const std::string& getExecPath() const;

#ifndef NDEBUG
    bool enableValidationLayers = true;
#else
    bool enableValidationLayers = false;
#endif
private:
    std::string executablePath;

};

}