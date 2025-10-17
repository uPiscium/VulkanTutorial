#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>
#include <vulkan/vulkan.hpp>

#include <array>
#include <chrono>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#ifndef STB_IMAGE_IMPLEMENTATION // Avoid multiple definition error
#define STB_IMAGE_IMPLEMENTATION
#else
#undef STB_IMAGE_IMPLEMENTATION
#endif
#define STB_IMAGE_STATIC
#include <stb/stb_image.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>

#include <tinyobjloader/tiny_obj_loader.h>

namespace VulkanTutorial {

typedef std::string str;
typedef int8_t i8;
typedef uint8_t u8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

template <typename T, size_t N> using array = std::array<T, N>;
template <typename T> using vec = std::vector<T>;
template <typename K, typename V> using umap = std::unordered_map<K, V>;
template <typename T> using uset = std::unordered_set<T>;

static constexpr u32 SDL_FLAGS =
    SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK | SDL_INIT_GAMEPAD |
    SDL_INIT_HAPTIC | SDL_INIT_CAMERA | SDL_INIT_SENSOR | SDL_INIT_AUDIO;
static constexpr u32 MAX_FRAMES_IN_FLIGHT = 2;
static constexpr char const *ENGINE_NAME = "Terreate";
static constexpr int WINDOW_WIDTH = 800;
static constexpr int WINDOW_HEIGHT = 600;
static constexpr u32 ENGINE_VERSION = VK_MAKE_VERSION(0, 1, 0);
static constexpr char const *MODEL_PATH =
    "assets/models/viking_room/viking_room.obj";
static constexpr char const *TEXTURE_PATH =
    "assets/models/viking_room/viking_room.png";

static constexpr char const *VALIDATION_LAYERS[] = {
    "VK_LAYER_KHRONOS_validation"};
static constexpr char const *DEVICE_EXTENSIONS[] = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME};

struct QueueFamilyIndices {
  i32 graphicsFamily = -1;
  i32 presentFamily = -1;

  bool isComplete() const { return graphicsFamily * presentFamily >= 0; }
  operator uset<i32>() const;
};

struct SwapChainSupportDetails {
  VkSurfaceCapabilitiesKHR capabilities;
  vec<VkSurfaceFormatKHR> formats;
  vec<VkPresentModeKHR> presentModes;
};

} // namespace VulkanTutorial
