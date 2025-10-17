#include <util.hpp>

namespace VulkanTutorial::Util {
VKAPI_ATTR VkBool32 VKAPI_CALL
debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
              VkDebugUtilsMessageTypeFlagsEXT messageType,
              VkDebugUtilsMessengerCallbackDataEXT const *pCallbackData,
              void *pUserData) {
  switch (messageSeverity) {
  case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
    return VK_FALSE;
    std::cerr << "VERBOSE: ";
    break;
  case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
    return VK_FALSE;
    std::cerr << "INFO: ";
    break;
  case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
    return VK_FALSE;
    std::cerr << "WARNING: ";
    break;
  case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
    std::cerr << "ERROR: ";
    break;
  default:
    std::cerr << "UNKNOWN: ";
    break;
  }
  std::cerr << pCallbackData->pMessage << std::endl;
  return VK_FALSE;
}

vec<char> readFile(str const &filename) {
  std::ifstream file(filename, std::ios::ate | std::ios::binary);

  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file.");
  }

  size_t fsize = (size_t)file.tellg();
  vec<char> buffer(fsize);
  file.seekg(0);
  file.read(buffer.data(), fsize);
  file.close();

  return buffer;
}
} // namespace VulkanTutorial::Util
