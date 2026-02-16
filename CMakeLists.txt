cmake_minimum_required(VERSION 3.16)

project(pacpac VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Submodule SFML 
add_subdirectory(vendor/SFML)


# Submodule imgui-sfml calls ImGui through internals
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui)
set(IMGUI_SFML_FIND_SFML OFF) # should be off Because of Dependency issue
add_subdirectory(vendor/imgui-sfml)


# Main client CMake
add_subdirectory(client)


