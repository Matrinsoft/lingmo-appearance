cmake_minimum_required(VERSION 3.20)

project(lingmo-appearance-tests VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Test Gui)

add_executable(test_lingmotheme
    test_lingmotheme.cpp
)

target_link_libraries(test_lingmotheme PRIVATE
    Qt6::Core
    Qt6::Test
    Qt6::Gui
    lingmo-base
    lingmo-appearance
)

add_test(NAME test_lingmotheme COMMAND test_lingmotheme)
