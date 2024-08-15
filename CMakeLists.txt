cmake_minimum_required(VERSION 3.22)

#-------------------------------------------------------------------------------
#   vcpkg setup
#-------------------------------------------------------------------------------

if (NOT DEFINED VCPKG_ROOT)
    if (WIN32)
        set(VCPKG_ROOT "$ENV{userprofile}/vcpkg")
    else()
        set(VCPKG_ROOT "$ENV{HOME}/vcpkg")
    endif()
endif()

if (EXISTS "${VCPKG_ROOT}")
    set(VCPKG_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

    if (EXISTS "${VCPKG_TOOLCHAIN_FILE}")
        set(CMAKE_TOOLCHAIN_FILE "${VCPKG_TOOLCHAIN_FILE}" CACHE STRING "")
        message("-- Using vcpkg")
    endif()
endif()

#-------------------------------------------------------------------------------
#   project setup
#-------------------------------------------------------------------------------

set(target_name ui_demo_lvgl)

project(${target_name} C)

find_package(SDL2 CONFIG REQUIRED)

#-------------------------------------------------------------------------------
#   lvgl setup
#-------------------------------------------------------------------------------

set(LV_CONF_PATH ${CMAKE_CURRENT_LIST_DIR}/lv_conf.h)

add_subdirectory(lvgl)

target_include_directories(lvgl PUBLIC
    ${SDL2_INCLUDE_DIRS}
)

#-------------------------------------------------------------------------------
#   target setup
#-------------------------------------------------------------------------------

add_executable(${target_name})

target_sources(${target_name} PRIVATE
    src/main.c
    src/mouse_cursor_icon.c
    src/platform.h
    src/platform.c
)

target_link_libraries(${target_name} PRIVATE
    lvgl
    lvgl::demos
    ${SDL2_LIBRARIES}
)

target_compile_features(${target_name} PRIVATE
    c_std_99
)
