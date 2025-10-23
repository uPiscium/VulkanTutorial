include(options)
project(Chapter4)

add_executable(${PROJECT_NAME} src/main.cpp)

setup_include(${PROJECT_NAME})
setup_link(${PROJECT_NAME})
setup_common_module(${PROJECT_NAME})
setup_binary_dir(${PROJECT_NAME})
