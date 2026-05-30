#pragma once

#include <memory>
#include <vector>

namespace Nova {

class Object;

typedef std::vector<std::shared_ptr<Object>> ObjectList;

class Object : public std::enable_shared_from_this<Object> {
    friend class Engine;
public:
	Object() = default;
	virtual ~Object();

	/**
	 * @brief Process object, called once per frame.
	 * @param deltaTime Time elapsed since last frame in seconds.
	 */
	virtual void process(double deltaTime);

	/**
	 * @brief Adds a child object to this object.
	 * Note that I have no idea how you got a shared pointer to an object...
	 * @param child Shared pointer to the child object to add.
	 */
    void addChild(const std::shared_ptr<Object>& child);

	/** 
	 * @brief Removes a child object from this object.
	 * Note that this doesn't even make sense at all...
	 * @returns void early if child is null or not a child of this object.
	 * @param child Shared pointer to the child object to remove. (You don't have one? Too bad.)
	 */
    void removeChild(const std::shared_ptr<Object>& child);

	/**
	 * @brief Recursively clears all children from this object.
	 * This is the only reasonable function here...
	 */
    void clearChildren(); // recursive

	// Self removal (tbh a bit too real)
	/**
	 * @brief Removes this object from its parent, if it has one.
	 * Does nothing if there is no parent.
	 * Orphan
	 */
    void removeFromParent();

	/**
	 * @brief Queues this object for deletion by removing it from its parent and clearing its children.
	 * After calling this, there could be remaining ObjectRefs to this object, but they will be invalid.
	 * Thanks godot for inspiration
	 */
    void queueFree();
 
	// Accessors
	/**
	 * @brief Gets a reference to the parent object.
	 */
    std::weak_ptr<Object> getParent() const;

	/**
	 * @brief Get all of the childern.
	 * @todo Return array instead of vector?
	 * @return Vector of ObjectRefs to child objects.
	 */
    std::vector<std::weak_ptr<Object>> getChildren() const;
	
	/**
	 * @brief Get all children recursively.
	 * getChildrenRecursive().getChildrenRecursive()...getChildren()
	 * @return Vector of ObjectRefs to all descendant objects.
	 * @todo Return array instead.
	 */
    std::vector<std::weak_ptr<Object>> getChildrenRecursive() const;
private:
	std::weak_ptr<Object> parent;
	ObjectList children;
    bool registered = false;
	void setRegistered(bool v);
	bool isRegistered() const;
};

}
