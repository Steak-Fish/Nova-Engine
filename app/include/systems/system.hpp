#pragma once

#include "objects/object.hpp"

namespace Nova {

class System {
public:
    virtual void process(double deltaTime) = 0;
    virtual bool accept(std::shared_ptr<Object> obj) = 0;
};

}