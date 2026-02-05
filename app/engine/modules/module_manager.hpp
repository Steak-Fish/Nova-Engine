#include <vector>
#include <memory>

#include "modules/module.hpp"
#include "utility/config.hpp"

namespace Nova {

class ModuleManager {
public:
    ModuleManager(EngineConfig& engineConfig);

    void UnloadModules();

    ~ModuleManager();

private:
    void LoadModules(const std::vector<std::string>& modulePaths);

    std::vector<std::unique_ptr<INovaModule>> modules;
};

} // namespace Nova