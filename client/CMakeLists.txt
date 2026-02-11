cmake_minimum_required(VERSION 3.16)


project(pacpac)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)


add_executable(pacpac
    src/main.cpp
    src/game/gamepanel.cpp
    src/engine/consoleLog.cpp
)

target_link_libraries(pacpac PRIVATE sfml-graphics sfml-window sfml-system)

target_include_directories(pacpac PRIVATE include)
