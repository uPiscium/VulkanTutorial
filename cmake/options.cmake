set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(DEBUG_BUILD)
  message(STATUS "[SYSTEM] Building with debug flags.")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -Wextra -fsanitize=address,undefined -fno-omit-frame-pointer")
  add_compile_definitions(TERREATE_DEBUG_BUILD)
else()
  message(STATUS "[SYSTEM] Building with release flags.")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra")
endif()

