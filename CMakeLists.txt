cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)
find_package(glm REQUIRED)


add_library(EngineLib src/CollisionManager.cpp src/Engine.cpp src/Renderer.cpp src/RigidBody.cpp src/World.cpp)
target_include_directories(EngineLib PUBLIC include)

target_link_libraries(EngineLib PUBLIC sfml-graphics sfml-window sfml-system glm::glm)

add_executable(EngineApp app/main.cpp)

target_link_libraries(EngineApp PRIVATE EngineLib)