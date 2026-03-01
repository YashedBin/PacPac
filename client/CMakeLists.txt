cmake_minimum_required(VERSION 3.16)
project(pacpac)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# files to add into executable
add_executable(pacpac
    src/main.cpp

    src/core/fileloader.cpp

    src/engine/spritemanager.cpp

    src/entities/pacman.cpp

    src/game/gamepanel.cpp
    src/game/map.cpp
    src/game/entitymanager.cpp
    src/game/eventhandler.cpp
)

target_precompile_headers(pacpac PRIVATE
    <SFML/Graphics.hpp>
    <SFML/Window.hpp>
    <SFML/System.hpp>
    <iostream>
    <string>
    <vector>
    <memory>
    <chrono>
    "include/core/consolelog.hpp"
    "include/core/timer.hpp"
)

# include libraries for:
# Client/Include 
# Vendor/Imgui for imgui-sfml
target_include_directories(pacpac PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/imgui
)

# link libraries to be made
target_link_libraries(pacpac PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    ImGui-SFML::ImGui-SFML
)

if(WIN32)
    # the Console Window Popups it toggle off 
    # to look at stdout/stderrs comment out
    set_target_properties(pacpac PROPERTIES WIN32_EXECUTABLE TRUE)

    # MSVC-specific flags
    if(MSVC)
        target_compile_options(pacpac PRIVATE /W3 /utf-8)
    endif()
endif()

if(UNIX)
    target_link_libraries(pacpac PRIVATE pthread)
endif()


add_custom_command(TARGET pacpac POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:pacpac>/assets
    COMMENT "Copying assets..."
)
