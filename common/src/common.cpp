#include <common.hpp>

namespace VulkanTutorial {

QueueFamilyIndices::operator uset<i32>() const {
  if (this->isComplete()) {
    return uset<i32>{graphicsFamily, presentFamily};
  } else {
    return uset<i32>{};
  }
}

} // namespace VulkanTutorial
