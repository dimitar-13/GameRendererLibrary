cmake_minimum_required(VERSION 3.20)
project(Sandbox VERSION 1.0)


#file(GLOB helloworld_SRC CONFIGURE_DEPENDS "*.h" "*.cpp")
add_executable(Sandbox "Sandbox/Game.cpp")

file(GLOB rendererLib_src CONFIGURE_DEPENDS "src/*.h" "include/*.h" "src/*.cpp")
add_library(RendererLib ${rendererLib_src})

add_subdirectory(vendors/glfw)
add_subdirectory(vendors/fmt)
add_subdirectory(vendors/glm)

target_include_directories(RendererLib PUBLIC vendors/glfw/include)
target_include_directories(RendererLib PUBLIC vendors/glm/include)
target_include_directories(RendererLib PUBLIC vendors/fmt/include)
target_include_directories(RendererLib PUBLIC vendors/glew/include)

target_include_directories(Sandbox PUBLIC vendors/glfw/include)
target_include_directories(Sandbox PUBLIC vendors/glm/include)
target_include_directories(Sandbox PUBLIC vendors/fmt/include)
target_include_directories(Sandbox PUBLIC vendors/glew/include)

target_link_directories(RendererLib vendors/glfw/cmake)
