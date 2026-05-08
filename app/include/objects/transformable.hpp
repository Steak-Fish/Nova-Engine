#pragma once

#include <iostream>

#include "object.hpp"
#include "primatives/transform.hpp"

namespace Nova {

class Transformable : public Object {
public:
    void process(double) override {
        std::cout << "Engine Processed Object!" << std::endl;
    }

    void doSomethingTransformy() {
        std::cout << "System processed Object!" << std::endl;    
    }
protected:
    Transform transform;
};

}