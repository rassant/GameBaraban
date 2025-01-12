cmake_minimum_required(VERSION 3.2)
project(game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

set(RESOURCE_PATH "${CMAKE_SOURCE_DIR}/resource")
file(COPY ${RESOURCE_PATH} DESTINATION ${CMAKE_BINARY_DIR})

set(SOURCES 
    ./main.cpp
    ./source/animation.cpp
    ./source/baraban.cpp
    ./source/baraban_solo.cpp
    ./source/button.cpp
    ./source/commentary.cpp
    ./source/game.cpp
    ./source/icon_elements.cpp
    ./source/interface.cpp
    ./source/mouse_controller.cpp
    ./source/resource.cpp
    ./source/text.cpp
)

add_executable(game ${SOURCES})
target_link_libraries(game sfml-graphics sfml-window sfml-system)

