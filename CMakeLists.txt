cmake_minimum_required(VERSION 3.24)
project(DSAWorkspace LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# AddressSanitizer + UndefinedBehaviorSanitizer catch out-of-bounds access,
# use-after-free and leaks -- invaluable when learning pointers and linked lists.
option(DSA_SANITIZE "Build Debug targets with ASan and UBSan" ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

# Every lessons/<topic>/<lesson>/<problem>/solution_test.cpp becomes its own
# test executable named "<lesson-number>-<problem>", e.g. "02-remove-element".
file(GLOB_RECURSE DSA_TEST_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/lessons/*_test.cpp)

foreach(test_source IN LISTS DSA_TEST_SOURCES)
    get_filename_component(problem_dir ${test_source} DIRECTORY)
    get_filename_component(problem ${problem_dir} NAME)
    get_filename_component(lesson_dir ${problem_dir} DIRECTORY)
    get_filename_component(lesson ${lesson_dir} NAME)
    string(REGEX MATCH "^[0-9]+" lesson_number ${lesson})
    set(target "${lesson_number}-${problem}")

    add_executable(${target} ${test_source})
    target_link_libraries(${target} PRIVATE GTest::gtest_main)
    target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic -Wshadow)
    if(DSA_SANITIZE AND CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(${target} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
        target_link_options(${target} PRIVATE -fsanitize=address,undefined)
    endif()
    gtest_discover_tests(${target})
endforeach()

# Every lessons/<topic>/<lesson>/playground/<name>.cpp is a standalone program with its own
# main(), for experimenting with a lesson's code. Target: "<lesson-number>-pg-<name>".
file(GLOB DSA_PLAYGROUND_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/lessons/*/*/playground/*.cpp)

foreach(playground_source IN LISTS DSA_PLAYGROUND_SOURCES)
    get_filename_component(name ${playground_source} NAME_WE)
    get_filename_component(playground_dir ${playground_source} DIRECTORY)
    get_filename_component(lesson_dir ${playground_dir} DIRECTORY)
    get_filename_component(lesson ${lesson_dir} NAME)
    string(REGEX MATCH "^[0-9]+" lesson_number ${lesson})
    set(target "${lesson_number}-pg-${name}")

    add_executable(${target} ${playground_source})
    target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic -Wshadow)
    if(DSA_SANITIZE AND CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(${target} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
        target_link_options(${target} PRIVATE -fsanitize=address,undefined)
    endif()
endforeach()
