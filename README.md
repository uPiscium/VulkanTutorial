# About this repository
This repositry contains the basic Vulkan examples and tutorials based on the [Vulkan Tutorial](https://vulkan-tutorial.com/).

In this repositry, I have used SDL3 for window creation and input handling instead of GLFW, which is used in the original tutorial. The code is also updated to use C++23 features and the latest Vulkan API.

# Prerequisites
- A C++ compiler that supports C++23 or later.
- CMake 3.30 or later.
- Vulkan SDK installed. You can download it from [LunarG](https://vulkan.lunarg.com/).
- A graphics card that supports Vulkan.

It is recommended to install [SDL3](https://www.libsdl.org/) to your system to run the examples. If cmake cannot find SDL3, it will download and build SDL3 automatically.

# Building the examples
1. Clone this repository:
   ```bash
   git clone https://github.com/upiscium/VulkanTutorial.git
   cd VulkanTutorial
   ```

2. Create a build directory (in this case, named `build`):
   ```bash
   mkdir build
   ```

3. Configure the project with CMake:
   ```bash
   cmake -S . -B build
   ```

4. Build the project:
   ```bash
   cmake --build build
   ```

5. Run the examples:
   Run the desired example executable. For example to run the "Hello Triangle" example:
   ```bash
   cd build
   ./build/chapter4
   ```

# License
This project is licensed under the BSD3-Clause License. See the [LICENSE](LICENSE) file for details

# Acknowledgements
- The original [Vulkan Tutorial](https://vulkan-tutorial.com/) by Alexander Overvoorde.
- The Vulkan SDK provided by LunarG.

# Contact
For any questions or suggestions, please open an issue in this repository.
