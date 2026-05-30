#include "scene.hpp"

namespace Nova {

void Scene::process(double dt) {

}

void Scene::enqueueRegistration(std::weak_ptr<Object> obj) {
    if (std::find(unregistered.begin(), unregistered.end(), obj) == unregistered.end()) {
        unregistered.push_back(obj);
    }
}

}