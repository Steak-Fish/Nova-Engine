# Nova Engine

## Overview

Nova Engine is the key component in a project called Ignis, Ingis is a game distrobution platform similar to roblox, while Nova Engine is the game engine behind Ingnis.

Nova Engine is a powerful and modern game development framework built with Vulkan. Designed to provide an intuitive and efficient way to create games, this engine allows you to build complex games with simple controls. Featuring an object oriented structure, automatic resource loading, and drag-and-drop simplicity, Nova Engine is perfect for both novice and experienced game developers.

## Features

- **Vulkan-Based Rendering**: Leverage the full power of Vulkan for high-performance graphics.
- **Object-Oriented Design**: Easily manage game objects and components with a clean, modular OOP structure.
- **Automatic Resource Loading**: Simply drop your assets into `src/resources/` and they are instantly available in your game.
- **Drag-and-Drop Simplicity**: Streamline your development process with easy-to-use drag-and-drop functionality for resources.
- **Futuristic Capabilities**: Cutting-edge features designed to support advanced game mechanics and graphics.
- **Project Structure Rethinked**: The Object-Oriented Design of this project allows for simple yet powerful parallelized systems.

## Getting Started

### Prerequisites

Before you begin, ensure you have met the following requirements:
- Operating System: Linux (Windows support is coming)
- [Vulkan SDK](https://vulkan.lunarg.com/sdk/home)
- [GLM](https://github.com/g-truc/glm)
- glslc
- C++ Compiler (Ideally GCC)
- CMake

For example on an Ubuntu based system:
```bash
sudo apt update
sudo apt install cmake build-essential libvulkan-dev vulkan-tools libglfw3 libglfw3-dev libglm-dev ninja-build
```

### Installation

1. **Clone the Repository**
   ```bash
   git clone https://github.com/CoolManTheCool/Nova-Engine.git
   cd NovaEngine
   ```

2. **Make sure to initalize git submodules**
   ```bash
   git submodule update --init --recursive
   ```

3. **Build and install the Project**
   ```bash
   mkdir -p build && cd build
   cmake -G Ninja ../app
   sudo ninja install
   ```

### Using Nova Engine in Your Project

To use Nova Engine in your project, follow these steps:

1. **Include the Engine Header**
   ```cpp
   #include "nova-engine/engine.hpp"
   ```

2. **Link against Nova Engine**
   ```cmake
   find_package(nova-engine REQUIRED)
   target_link_libraries(${PROJECT_NAME} PRIVATE nova-engine::nova-engine)
   # Note that any libraries that depend on ImGui must be built like (using imgui-knobs as an example):
   #target_link_libraries(imgui-knobs PRIVATE nova-engine::nova-engine)
   ```

### Example

Here's a simple example of how to create a window and run the engine:
-# This example is a placeholder and does not reflect the actual project, please look at the examples.

```cpp
#include "engine.hpp"

#include <iostream>

#include "imgui/imgui.h"
// #include "imgui.h" if not building against engine source

struct AppConfig {
    float someValue = 42.0;
};

void gameLogic(const Nova::FrameCtx&, void* userData) {
    AppConfig& cfg = *reinterpret_cast<AppConfig*>(userData);

    ImGui::Begin("Demo Window");
    ImGui::Text("Hello, Nova Engine with ImGui!");
    ImGui::SliderFloat("Some Value", &cfg.someValue, 0.0f, 100.0f);
    ImGui::End();
}

int main(void) {
    Nova::EngineConfig config;
    config.appMajorVer = 1;
    config.appMinorVer = 1;
    config.appPatchVer = 0;
    config.title = "Nova Engine Demo Application";
    AppConfig cfg;
    config.userData = &cfg;
    
    Nova::Engine engine(config);

    engine.loop(gameLogic);

    return 0;
}
```

### Contributing

Contributions are welcome! Please follow these steps to contribute:
1. Fork the repository.
2. Create a new branch.
3. Make your changes.
4. Commit your changes.
5. Push to the branch.
6. Create a pull request.

### License

This project is licensed under Nova Studios General Software License. See the [LICENSE](LICENSE) file for details.
Usage of this software in any way subjects you to this license. 

### Acknowledgements

- [Vulkan](https://www.vulkan.org/)
- [GLFW](https://www.glfw.org/)
- [GLM](https://github.com/g-truc/glm)
- [OpenAL](https://www.openal.org/) (Temporarily unused)

## Contact

For any inquiries, please contact [noahgrimes0915@gmail.com](mailto:noahgrimes0915@gmail.com).

---

Thank you for using Nova Engine! We look forward to seeing the amazing games you create.
