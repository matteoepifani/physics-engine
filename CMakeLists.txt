cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)
find_package(glm REQUIRED)

file(GLOB OOP_SOURCES "lib_oop/src/*.cpp")

add_library(ObjectEngine ${OOP_SOURCES})

target_include_directories(ObjectEngine PUBLIC lib_oop/include)
target_link_libraries(ObjectEngine PUBLIC sfml-graphics sfml-window sfml-system glm::glm)

file(GLOB ECS_SOURCES "lib_ecs/src/*.cpp")

add_library(ECSEngine ${ECS_SOURCES})

target_include_directories(ECSEngine PUBLIC lib_ecs/include)
target_link_libraries(ECSEngine PUBLIC sfml-graphics sfml-window sfml-system glm::glm)


add_executable(BenchmarkApp app/main.cpp)

target_link_libraries(BenchmarkApp PRIVATE ObjectEngine ECSEngine)