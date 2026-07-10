cmake_minimum_required(VERSION 3.20)

project(lingmo-appearance VERSION 1.0.0 DESCRIPTION "Lingmo Appearance Library" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui)

add_library(lingmo-appearance SHARED
    src/lingmoaccentcolor.cpp
    src/lingmocolor.cpp
    src/lingmotheme.cpp
)

target_include_directories(lingmo-appearance
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(lingmo-appearance
    PUBLIC
        Qt6::Core
        Qt6::Gui
        lingmo-base
)

include(GenerateExportHeader)
generate_export_header(lingmo-appearance
    EXPORT_MACRO_NAME LINGMO_APPEARANCE_EXPORT
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/export.h
)

install(TARGETS lingmo-appearance
    EXPORT LingmoAppearanceTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/lingmo-appearance
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT LingmoAppearanceTargets
    FILE LingmoAppearanceTargets.cmake
    NAMESPACE LingmoSdk::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/LingmoAppearance
)
