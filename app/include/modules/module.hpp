#pragma once
#include <string>

#ifdef _WIN32
#define MODULE_API __declspec(dllexport)
#else
#define MODULE_API __attribute__((visibility("default")))
#endif

class INovaModule {
public:
    virtual std::string GetName() const = 0;

    // Called when the module is loaded at runtime (optional for library-only modules)
    virtual void OnLoad()   = 0;
    virtual void OnUnload() = 0;

    virtual ~INovaModule() = default;
};