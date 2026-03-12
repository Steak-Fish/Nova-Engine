#include "objects/object.hpp"
#include "objects/object_ref.hpp"

#include <iostream>
#include <stdexcept>

namespace Nova {

void Object::update(double /*deltaTime*/) {}

void Object::render(RenderData& /*renderData*/) {}

void Object::addChild(const std::shared_ptr<Object>& child) {
    if (!child) return;

    // Prevent duplicates
    if (std::find(children.begin(), children.end(), child) != children.end())
        return;

    // Remove from previous parent
    if (auto oldParent = child->parent.lock()) {
        oldParent->removeChild(child);
    }

    child->parent = shared_from_this();
    children.push_back(child);
}

void Object::removeChild(const std::shared_ptr<Object>& child) {
    if (!child) return;

    auto it = std::find(children.begin(), children.end(), child);
    if (it != children.end()) {
        child->parent.reset();
        children.erase(it);
    }
}

void Object::clearChildren() {
    for (auto& c : children) {
        c->clearChildren();
        c->parent.reset();
    }
    children.clear();
}

void Object::removeFromParent() {
    if (auto p = parent.lock()) {
        p->removeChild(shared_from_this());
    }
    parent.reset();
}

void Object::queueFree() {
    removeFromParent();
    clearChildren();
}

ObjectRef<Object> Object::getParent() const {
    return ObjectRef<Object>(parent.lock());
}

std::vector<ObjectRef<Object>> Object::getChildren() const {
    std::vector<ObjectRef<Object>> refs;
    for (auto& c : children) {
        refs.emplace_back(c);
    }
    return refs;
}

std::vector<ObjectRef<Object>> Object::getChildrenRecursive() const {
    std::vector<ObjectRef<Object>> refs;
    for (auto& c : children) {
        auto childRefs = c->getChildrenRecursive();
        refs.insert(refs.end(), childRefs.begin(), childRefs.end());
        refs.emplace_back(c);
    }
    return refs;
}

Object::~Object() {
    clearChildren();
}

} // namespace Nova