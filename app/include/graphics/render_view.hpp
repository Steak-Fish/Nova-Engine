#pragma once

#include "objects/camera.hpp"
#include "graphics/render_target.hpp"

#include <memory>

namespace Nova {

/**
 * @brief Represents 
 * @note Can be owned by anymore.
 */
class RenderView {
public:
    /**
     * @brief Stores a weak pointer, if you delete the camera it just won't render.
     * @param camera *Should* be owned by the engine, but I can't stop you.
     */
    void setCamera(std::shared_ptr<Camera> camera);
    /**
     * @brief Stores a shared pointer, if you delete the target, we'll still have it.
     * @param target User owned 
     */
    void setTarget(std::shared_ptr<RenderTarget> target);
private:
    std::weak_ptr<Camera> camera;
    std::shared_ptr<RenderTarget> target;
};

}