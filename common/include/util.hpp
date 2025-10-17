#pragma once

#include <common.hpp>

namespace VulkanTutorial::Util {
VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    VkDebugUtilsMessengerCallbackDataEXT const *pCallbackData, void *pUserData);

vec<char> readFile(str const &filename);
} // namespace VulkanTutorial::Util
