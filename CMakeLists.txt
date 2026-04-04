cmake_minimum_required(VERSION 4.2)
project(SDL3Project)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

add_executable(SDL3Project main.cpp
        UI/Window.cpp
        UI/Window.h
        UI/Renderer.cpp
        UI/Renderer.h
        MANAGER/Game.cpp
        MANAGER/Game.h
        PLAYER/Player.cpp
        PLAYER/Player.h
        PLAYER/PlayerMovement.cpp
        PLAYER/PlayerMovement.h)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/ASSETS
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(SDL3Project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(SDL3Project
        PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
)



