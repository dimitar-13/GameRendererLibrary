cmake_minimum_required(VERSION 3.20)
project(Sandbox VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#file(GLOB helloworld_SRC CONFIGURE_DEPENDS "*.h" "*.cpp")
add_executable(Sandbox 
${CMAKE_CURRENT_SOURCE_DIR}/Sandbox/Sandbox.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Sandbox/GameScripts/ExampleScript.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Sandbox/GameScripts/ExampleScript.h
)

add_library(RendererLib 
${CMAKE_CURRENT_SOURCE_DIR}/scr/SystemManager.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/SystemManager.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/Texture2D.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/TextureUnitManager.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/TextureUnitManager.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/VertexArray.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/VertexArray.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/Window.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/Window.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/WindowFunctions.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/WindowFunctions.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/Colider.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/CollisionDetection.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/CollisionDetection.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/CollisionSolver.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/CollisionSolver.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/CollisionSytstem.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/CollisionSytstem.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/ComponentArray.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/ComponentManager.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/ECSManager.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/ECSManager.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/ECSTypes.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/EntityManager.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/EntityManager.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/EntryPoint.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/EntryPoint.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/GameObject.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/GameObjectRegister.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/GameObjectRegister.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/Input.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/ISystem.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/Log.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/Log.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/MetricHelper.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/PhysicWorld.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/PhysicWorld.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/Renderer.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/Renderer.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/Rendererpch.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/Rendererpch.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/RenderSytstem.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/RenderSytstem.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/Scene.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/ScriptSystem.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/ScriptSystem.h
${CMAKE_CURRENT_SOURCE_DIR}/scr/ShaderProgram.cpp
${CMAKE_CURRENT_SOURCE_DIR}/scr/ShaderProgram.h
${CMAKE_CURRENT_SOURCE_DIR}/include/Scene.h
${CMAKE_CURRENT_SOURCE_DIR}/include/ScriptableObject.h
${CMAKE_CURRENT_SOURCE_DIR}/include/Texture2D.h
${CMAKE_CURRENT_SOURCE_DIR}/include/DeltaTime.h
${CMAKE_CURRENT_SOURCE_DIR}/include/EventSystem.h
${CMAKE_CURRENT_SOURCE_DIR}/include/GameObject.h
${CMAKE_CURRENT_SOURCE_DIR}/include/Input.h
${CMAKE_CURRENT_SOURCE_DIR}/include/RendererEngine_s.h
${CMAKE_CURRENT_SOURCE_DIR}/include/Components/Component.h
${CMAKE_CURRENT_SOURCE_DIR}/include/Components/PhysicBody.h
${CMAKE_CURRENT_SOURCE_DIR}/include/Components/ScriptComponent.h
${CMAKE_CURRENT_SOURCE_DIR}/include/Components/Sprite.h
${CMAKE_CURRENT_SOURCE_DIR}/include/Components/TagComponent.h
${CMAKE_CURRENT_SOURCE_DIR}/include/Components/Transoform.h
${CMAKE_CURRENT_SOURCE_DIR}/include/Components/Camera.h
${CMAKE_CURRENT_SOURCE_DIR}/include/Colider.h
${CMAKE_CURRENT_SOURCE_DIR}/include/Components/ColliderComponent.h
)
add_subdirectory(vendors/glfw)
add_subdirectory(vendors/fmt)
add_subdirectory(vendors/glm)
add_subdirectory(vendors/glew-2.2.0/build/cmake)
target_precompile_headers(RendererLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/scr/Rendererpch.h)
# Find the GLEW library

target_include_directories(RendererLib PUBLIC vendors/glfw/include)
target_include_directories(RendererLib PUBLIC vendors/glm)
target_include_directories(RendererLib PUBLIC vendors/fmt/include)
target_include_directories(RendererLib PUBLIC vendors/glew/include)
target_include_directories(RendererLib PUBLIC vendors/stbi_image)
target_include_directories(RendererLib PRIVATE
  vendors/glew-2.2.0/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/scr
)
target_include_directories(Sandbox PUBLIC vendors/glfw/include)
target_include_directories(Sandbox PUBLIC vendors/glm)
target_include_directories(Sandbox PUBLIC vendors/fmt/include)
target_include_directories(Sandbox PUBLIC vendors/glew/include)
target_include_directories(Sandbox PUBLIC vendors/stbi_image)
target_include_directories(Sandbox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Sandbox)


target_include_directories(Sandbox PRIVATE
  vendors/glew-2.2.0/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/scr
)
target_link_directories(Sandbox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendors/glfw/src/Debug)
target_link_directories(Sandbox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/Debug)
target_link_directories(Sandbox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendors/glew-2.2.0/lib)
target_link_directories(Sandbox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Debug)

add_compile_definitions(Sandbox PUBLIC GLEW_STATIC)
add_compile_definitions(RendererLib PUBLIC GLEW_STATIC)


target_link_libraries(Sandbox 
PUBLIC glfw3
PUBLIC libglew32d
PUBLIC opengl32
PUBLIC RendererLib.lib)

add_dependencies(Sandbox RendererLib)
add_dependencies(RendererLib glfw fmt glm glew_s)