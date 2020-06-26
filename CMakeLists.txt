cmake_minimum_required(VERSION 3.10)
project(gui_wrapper VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(dependencies)
add_subdirectory(src)

set (GUI_WRAPPER_LIBRARIES ${GUI_SUBPROJECTS} PARENT_SCOPE)
