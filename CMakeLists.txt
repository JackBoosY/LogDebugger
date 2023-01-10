cmake_minimum_required(VERSION 3.14)

project(LogDebugger CXX)

option(BUILD_DEBUGGER_TOOL "Build debugger executable" OFF)
option(ENABLE_SOURCE_CONTROL "Enable source code version control" ON)
option(ENABLE_PROCESS_CONTROL "Enable procees id control" ON)
cmake_dependent_option(ENABLE_THREAD_CONTROL "Enable thread id control" ON "ENABLE_PROCESS_CONTROL" OFF)

add_subdirectory(src)

if (BUILD_DEBUGGER_TOOL)
    add_subdirectory(tool)
endif()
