#pragma once

#include "utility/config.hpp"

struct GLFWwindow;
struct VkExtent2D;
struct VkInstance_T;
struct VkSurfaceKHR_T;
typedef VkInstance_T *VkInstance;
typedef VkSurfaceKHR_T *VkSurfaceKHR;

namespace Nova {

struct WindowState {
    uint32_t width;
    uint32_t height;
};

class Window {
public:
    explicit Window(const EngineConfig& config);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    bool shouldClose();
    const WindowState& getWindowState() const noexcept;
    void pollEvents() const noexcept;

    void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
    
    VkExtent2D getExtent();
    bool wasWindowResized() const;
    void resetWindowResizedFlag();
    GLFWwindow* getWindow() const;
private:

    static void frameBufferResizeCallback(GLFWwindow* window, int width, int height);

	bool frameBufferResized = false;

    WindowState state;
    GLFWwindow* window = nullptr;
};

}
