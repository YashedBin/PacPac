cmake_minimum_required(VERSION 3.16)
project(pacpac VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# build's dir place
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Static linking ( DLL later ) 
set(BUILD_SHARED_LIBS OFF)
set(SFML_BUILD_AUDIO     OFF)
set(SFML_BUILD_NETWORK   OFF)

add_subdirectory(vendor/SFML)

# setting Vendors before calling Client
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui)
set(IMGUI_SFML_FIND_SFML OFF)
add_subdirectory(vendor/imgui-sfml)

add_subdirectory(client)