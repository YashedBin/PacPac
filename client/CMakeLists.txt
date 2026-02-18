cmake_minimum_required(VERSION 3.16)

project(pacpac)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(COPY ${CMAKE_SOURCE_DIR}/client/assets DESTINATION ${CMAKE_BINARY_DIR})

# files to add into executable
add_executable(pacpac
    src/main.cpp
    src/game/gamepanel.cpp
    src/game/map.cpp
    src/core/fileloader.cpp
    src/engine/consoleLog.cpp
)

# link libraries to be made
target_link_libraries(pacpac PRIVATE 
        sfml-graphics 
        sfml-window 
        sfml-system
        ImGui-SFML::ImGui-SFML
)


# include libraries for:
# Client/Include 
# Vendor/Imgui for imgui-sfml
target_include_directories(pacpac PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/imgui
)
