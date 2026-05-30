#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace Nova {

/**
 * @brief ONLY for engine initalization.
 */
class EngineConfig {
public:
    EngineConfig();

    /**
     * Application Config
     */
    uint32_t width  = 960;
    uint32_t height = 540;
    
    // Version: Major.Minor.Patch
    uint32_t appMajorVer = 1;
    uint32_t appMinorVer = 0;
    uint32_t appPatchVer = 0;

    std::string title = "Untitled Application | Nova Engine";

    /**
     * Engine Config
     */

    // Version: Major.Minor.Patch
    const uint32_t EngMajorVer = 10;
    const uint32_t EngMinorVer = 1;
    const uint32_t EngPatchVer = 0;

    /**
     * @brief Do NOT forget to null terminate.
     */
    const char* engineName = "Nova Engine\0";

    bool     forceGPU = false;
    uint32_t forceGPUID;

    const std::string& getExecPath() const;
    std::vector<std::string> getModulePaths();

#ifndef NDEBUG
    bool enableValidationLayers = true;
    const bool debug = true;
#else
    bool enableValidationLayers = false;
    const bool debug = false;
#endif
private:
    std::string executablePath;

};

}
