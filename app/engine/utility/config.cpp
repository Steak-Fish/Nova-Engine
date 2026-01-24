#include "utility/config.hpp"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <limits.h>
#endif

#include <iostream>
#include <iterator>
#include <filesystem>
namespace fs = std::filesystem;

namespace Nova {

std::string getExecutableDirectory() {
    std::string executablePath;

    // Get the full path to the executable
#ifdef _WIN32
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    executablePath = std::string(buffer);
#else
    char buffer[PATH_MAX];
    ssize_t length = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (length != -1) {
        buffer[length] = '\0';
        executablePath = std::string(buffer);
    }
#endif
    // Use std::filesystem to get the parent path
    std::filesystem::path pathObj = std::filesystem::path(executablePath).parent_path();
    // Convert to string and remove the trailing slash/backslash
    std::string directory = pathObj.string();
    // Remove trailing slash or backslash if present
    if (!directory.empty() && (directory.back() == '/' || directory.back() == '\\')) {
        directory.pop_back();
    }

    return directory;
}

EngineConfig::EngineConfig() {
    executablePath = getExecutableDirectory();
}

const std::string& EngineConfig::getExecPath() const {
    return executablePath;
}

}