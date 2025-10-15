# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find external packages needed by both libraries
find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)
find_package(glm REQUIRED)

# --- 1. Define the OOP Library ---
# Find its source files
file(GLOB OOP_SOURCES "lib_oop/src/*.cpp")
# Create the library target
add_library(ObjectEngine ${OOP_SOURCES})
# Provide its public headers and link its dependencies
target_include_directories(ObjectEngine PUBLIC lib_oop/include)
target_link_libraries(ObjectEngine PUBLIC sfml-graphics sfml-window sfml-system glm::glm)

# --- 2. Define the ECS Library ---
# Find its source files
file(GLOB ECS_SOURCES "lib_ecs/src/*.cpp")
# Create the library target
add_library(ECSEngine ${ECS_SOURCES})
# Provide its public headers and link its dependencies
target_include_directories(ECSEngine PUBLIC lib_ecs/include)
target_link_libraries(ECSEngine PUBLIC sfml-graphics sfml-window sfml-system glm::glm)

# --- 3. Define the Main Application ---
add_executable(BenchmarkApp app/main.cpp)
# Link BOTH physics libraries to the main app
target_link_libraries(BenchmarkApp PRIVATE ObjectEngine ECSEngine)