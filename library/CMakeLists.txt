cmake_minimum_required(VERSION 4.3.0 FATAL_ERROR)
project(library VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(MyLib STATIC)

find_package(spdlog REQUIRED)
target_link_libraries(MyLib PRIVATE spdlog::spdlog)

target_sources(MyLib
    PUBLIC
        FILE_SET HEADERS
        FILES
            MyLib.hpp
    PRIVATE
        FILE_SET SOURCES
        FILES
            Impl.cpp
)

#---------------------------------------------------------------------------------------------------
# Installation (based on: https://crascit.com/2024/04/04/cxx-modules-cmake-shared-libraries/)

include(GNUInstallDirs)
install(TARGETS MyLib
    EXPORT MyLib-targets
    FILE_SET CXX_MODULES
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyLib/src
    FILE_SET HEADERS
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/include
)
install(EXPORT MyLib-targets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyLib
    CXX_MODULES_DIRECTORY .
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    mylib-config.cmake.in
    ${PROJECT_BINARY_DIR}/mylib-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MyLib
)
install(
    FILES
        ${PROJECT_BINARY_DIR}/mylib-config.cmake
    DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/MyLib
)