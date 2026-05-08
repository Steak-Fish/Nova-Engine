#include "objects/object.hpp"

#include <algorithm>

namespace Nova {

void Object::process(double deltaTime) {

}

void Object::addChild(const std::shared_ptr<Object>& child) {
    if (!child) return;

    // Prevent duplicates unreadably
    if (std::find_if(children.begin(), children.end(),
        [&](const std::shared_ptr<Object>& c) {
            return c.get() == child.get();
        }) != children.end()) return;

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

std::weak_ptr<Object> Object::getParent() const {
    return std::weak_ptr<Object>(parent.lock());
}

std::vector<std::weak_ptr<Object>> Object::getChildren() const {
    std::vector<std::weak_ptr<Object>> refs;
    for (auto& c : children) {
        refs.emplace_back(c);
    }
    return refs;
}

std::vector<std::weak_ptr<Object>> Object::getChildrenRecursive() const {
    std::vector<std::weak_ptr<Object>> refs;
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

}