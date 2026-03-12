#pragma once

#include "graphics/primatives/abstract/texture.hpp"

#include <assert.h>

namespace Nova {

class Texture2D : public Texture {
public:
    Texture2D(uint32_t w, uint32_t h, TextureFormat fmt, const std::string& debugName = "")
        : m_width(w), m_height(h), m_format(fmt), m_name(debugName)
    {
        m_depth = 1;
        // Here you'd normally allocate GPU memory
        // e.g., Vulkan VkImage creation
    }

    virtual ~Texture2D() {
        // free GPU memory
    }

    uint32_t width() const override { return m_width; }
    uint32_t height() const override { return m_height; }
    uint32_t depth() const override { return m_depth; }
    TextureFormat format() const override { return m_format; }
    TextureType type() const override { return TextureType::Texture2D; }

    void upload(const void* data, size_t size, uint32_t mipLevel = 0) override {
        assert(data != nullptr);
        (void)size;
        (void)mipLevel;
    }

    void bind(uint32_t slot = 0) override {
        // Bind texture to shader slot
        (void)slot;
        // In a real engine: vkCmdBindDescriptorSets or glBindTexture
    }

    void generateMipmaps() override {
        
    };

    const std::string& name() const override { return m_name; }

private:
    uint32_t m_width;
    uint32_t m_height;
    uint32_t m_depth;
    TextureFormat m_format;
    std::string m_name;

    // Normally, GPU handles would go here
    // e.g., VkImage, VkImageView, VkDeviceMemory
};

}