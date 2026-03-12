#pragma once

#include "objects/object.hpp"
#include "primatives/transform.hpp"

namespace Nova {

class TransformableObject : public Object {
public:
    TransformableObject() = default;
    ~TransformableObject() override = default;
    Transform transform;
};

} // namespace Nova
