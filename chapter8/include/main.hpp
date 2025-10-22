#pragma once

#include <common.hpp>
#include <util.hpp>

namespace VulkanTutorial::Chapter8 {
static char const *const TEXTURE_PATH = "assets/textures/texture.jpg";

struct Vertex {
  glm::vec3 pos;
  glm::vec3 color;
  glm::vec2 texCoord;

  static VkVertexInputBindingDescription getBindingDescription();
  static vec<VkVertexInputAttributeDescription> getAttributeDescriptions();
};

struct UniformBufferObject {
  alignas(16) glm::mat4 model;
  alignas(16) glm::mat4 view;
  alignas(16) glm::mat4 proj;
};

static vec<Vertex> const VERTICES = {
    {{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
    {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
    {{-0.5f, 0.5f, 0.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},

    {{-0.5f, -0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
    {{0.5f, 0.5f, -0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
    {{-0.5f, 0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}};
static vec<u16> const INDICES = {0, 1, 2, 2, 3, 0, 4, 5, 6, 6, 7, 4};

class App {
private:
  bool mDebugMode = true;

  SDL_Window *mWindow;
  VkInstance mInstance = VK_NULL_HANDLE;
  VkDebugUtilsMessengerEXT mDebugMessenger = VK_NULL_HANDLE;
  VkSurfaceKHR mSurface = VK_NULL_HANDLE;

  VkPhysicalDevice mPhysicalDevice = VK_NULL_HANDLE;
  VkDevice mDevice = VK_NULL_HANDLE;

  VkQueue mGraphicsQueue = VK_NULL_HANDLE;
  VkQueue mPresentQueue = VK_NULL_HANDLE;

  VkSwapchainKHR mSwapchain = VK_NULL_HANDLE;
  vec<VkImage> mSwapchainImages;
  VkFormat mSwapchainImageFormat;
  VkExtent2D mSwapchainExtent;
  vec<VkImageView> mSwapchainImageViews;

  VkRenderPass mRenderPass = VK_NULL_HANDLE;
  VkDescriptorSetLayout mDescriptorSetLayout = VK_NULL_HANDLE;
  VkPipelineLayout mPipelineLayout = VK_NULL_HANDLE;
  VkPipeline mGraphicsPipeline = VK_NULL_HANDLE;
  vec<VkFramebuffer> mSwapchainFramebuffers;

  VkCommandPool mCommandPool = VK_NULL_HANDLE;
  vec<VkCommandBuffer> mCommandBuffers = {};

  VkImage mTexture = VK_NULL_HANDLE;
  VkDeviceMemory mTextureMemory = VK_NULL_HANDLE;
  VkImageView mTextureImageView = VK_NULL_HANDLE;
  VkSampler mTextureSampler = VK_NULL_HANDLE;

  VkImage mDepthImage = VK_NULL_HANDLE;
  VkDeviceMemory mDepthImageMemory = VK_NULL_HANDLE;
  VkImageView mDepthImageView = VK_NULL_HANDLE;

  VkBuffer mVertexBuffer = VK_NULL_HANDLE;
  VkDeviceMemory mVertexBufferMemory = VK_NULL_HANDLE;
  VkBuffer mIndexBuffer = VK_NULL_HANDLE;
  VkDeviceMemory mIndexBufferMemory = VK_NULL_HANDLE;

  vec<VkBuffer> mUniformBuffers;
  vec<VkDeviceMemory> mUniformBuffersMemory;
  vec<void *> mUniformBuffersMapped;

  VkDescriptorPool mDescriptorPool = VK_NULL_HANDLE;
  vec<VkDescriptorSet> mDescriptorSets;

  vec<VkSemaphore> mImageAvailableSemaphores = {};
  vec<VkSemaphore> mRenderFinishedSemaphores = {};
  vec<VkFence> mInFlightFences = {};

  u32 mCurrentFrame = 0;
  bool mFramebufferResized = false;

private:
  void initWindow(int const &width, int const &height, str const &title);

  bool checkValidationLayerSupport();
  vec<char const *> getRequiredExtensions();
  void populateDebugMessengerCreateInfo(
      VkDebugUtilsMessengerCreateInfoEXT &createInfo);
  void createInstance(str const &appName, u32 const &appVersion);

  VkResult createDebugUtilsMessengerEXT(
      VkDebugUtilsMessengerCreateInfoEXT const *pCreateInfo,
      VkAllocationCallbacks const *pAllocator);
  VkResult
  destroyDebugUtilsMessengerEXT(VkAllocationCallbacks const *pAllocator);
  void setupDebugMessenger();

  void createSurface();

  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
  bool checkDeviceExtensionSupport(VkPhysicalDevice device);
  SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
  int rateDevice(VkPhysicalDevice device);
  void pickPhysicalDevice();

  void createLogicalDevice();
  void createQueue();

  VkSurfaceFormatKHR
  chooseSwapSurfaceFormat(vec<VkSurfaceFormatKHR> const &availableFormats);
  VkPresentModeKHR
  chooseSwapPresentMode(vec<VkPresentModeKHR> const &availablePresentModes);
  VkExtent2D chooseSwapExtent(VkSurfaceCapabilitiesKHR const &capabilities);
  VkImageView createImageView(VkImage image, VkFormat format,
                              VkImageAspectFlags aspectFlags);
  void createSwapchain();
  void createImageViews();

  VkShaderModule createShaderModule(vec<char> const &code);

  void createCommandPool();

  VkFormat findSupportedFormat(vec<VkFormat> const &candidates,
                               VkImageTiling tiling,
                               VkFormatFeatureFlags features);
  VkFormat findDepthFormat();
  bool hasStencilComponent(VkFormat format);

  void createRenderPass();
  void createDescriptorSetLayout();
  void createGraphicsPipeline();
  void createDepthResources();
  void createFramebuffers();

  u32 findMemoryType(u32 typeFilter, VkMemoryPropertyFlags properties);
  void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage,
                    VkMemoryPropertyFlags properties, VkBuffer &buffer,
                    VkDeviceMemory &bufferMemory);
  VkCommandBuffer beginSingleTimeCommands();
  void endSingleTimeCommands(VkCommandBuffer commandBuffer);
  void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

  void createImage(u32 width, u32 height, VkFormat format, VkImageTiling tiling,
                   VkImageUsageFlags usage, VkMemoryPropertyFlags properties,
                   VkImage &image, VkDeviceMemory &imageMemory);
  void transitionImageLayout(VkImage image, VkFormat format,
                             VkImageLayout oldLayout, VkImageLayout newLayout);
  void copyBufferToImage(VkBuffer buffer, VkImage image, u32 width, u32 height);

  void createTexture();
  void createTextureImageView();
  void createTextureSampler();

  void createVertexBuffer();
  void createIndexBuffer();
  void createUniformBuffers();

  void createDescriptorPool();
  void createDescriptorSets();

  void createCommandBuffers();
  void recordCommandBuffer(VkCommandBuffer commandBuffer, u32 imageIndex);

  void createSyncObjects();

  void cleanupSwapchain();
  void recreateSwapchain();

  void initVulkan();
  bool pollEvents();
  void updateUniformBuffer(u32 currentImage);
  void drawFrame();
  void mainLoop();
  void cleanup();

public:
  App(int const &width = WINDOW_WIDTH, int const &height = WINDOW_HEIGHT,
      str const &title = "Vulkan Tutorial", bool debugMode = true);
  ~App();

  void run();
};

} // namespace VulkanTutorial::Chapter8

int main();
