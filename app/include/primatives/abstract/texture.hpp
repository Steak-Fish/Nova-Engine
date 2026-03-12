#pragma once
#include <cstdint>
#include <vector>
#include <string>

namespace Nova {

enum class TextureFormat {
    RGBA8,
    RGB8,
    Depth24,
    Depth32,
    // Add more formats as needed
};

enum class TextureType {
    Texture2D,
    Texture3D,
    Cubemap
};

class Texture {
public:
    virtual ~Texture() = default;

    virtual uint32_t width() const = 0;
    virtual uint32_t height() const = 0;
    virtual uint32_t depth() const = 0; // 1 for 2D

    virtual TextureFormat format() const = 0;
    virtual TextureType type() const = 0;

    // Upload raw pixel data to GPU
    virtual void upload(const void* data, size_t size, uint32_t mipLevel = 0) = 0;

    // Bind texture to a slot for shaders
    virtual void bind(uint32_t slot = 0) = 0;

    // Optional: generate mipmaps
    virtual void generateMipmaps() = 0;

    // Optional: name for debugging
    virtual const std::string& name() const = 0;
};

}