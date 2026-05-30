#pragma once

#include <iostream>

#include "object.hpp"

namespace Nova {

class Scene : public Object {
public:
    void process(double dt) override;
    void enqueueRegistration(std::weak_ptr<Object> obj);
private:
    std::vector<std::weak_ptr<Object>> unregistered;
};

}