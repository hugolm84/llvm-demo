cmake_minimum_required(VERSION 3.12)

project(
    llvm-demo
    VERSION 1.0.0
    DESCRIPTION "LLVM Clang-Tidy demo"
    LANGUAGES CXX
)

add_library(${PROJECT_NAME})

# Source files that the library depends on
target_sources(${PROJECT_NAME}
    PRIVATE
        src/aligned_buffer.cc
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
)

find_program(CLANG_TIDY_BIN NAMES "clang-tidy" "clang-tidy-6.0")

if(NOT CLANG_TIDY_BIN)
    message(FATAL_ERROR "clang-tidy not found.")
else()
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    message(STATUS "clang-tidy found: ${CLANG_TIDY_BIN}")
    set(DO_CLANG_TIDY "${CLANG_TIDY_BIN}" "-enable-check-profile" "-checks=''")
    message(STATUS "clang-tidy args: ${DO_CLANG_TIDY}")
endif()

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
)

target_compile_features(${PROJECT_NAME}
    PUBLIC
        cxx_std_11
)

if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    set(DEFAULT_LEVEL_REMOVED TRUE)
endif()

# This library is compiled with Wall, but do not require clients to have any specific warning level
target_compile_options(${PROJECT_NAME}
    PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
            $<$<CONFIG:Debug>:-O0 -Wall -Wextra>>
        $<$<CXX_COMPILER_ID:MSVC>:
            $<$<CONFIG:Debug>:/Od /W4 /Zi>>
)
