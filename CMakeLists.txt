cmake_minimum_required(VERSION 4.0)
project(kursovaya)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(kursovaya
        main.cpp
        Graph.cpp
        Graph.h
)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(kursovaya_tests
        tests/GraphTest.cpp
        Graph.cpp
        Graph.h
)

target_link_libraries(kursovaya_tests
        PRIVATE
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(kursovaya_tests)
