cmake_minimum_required(VERSION 3.16)

project(nokia_test)

add_executable(nokia_test main.cpp)

target_include_directories(nokia_test PRIVATE headers)
target_include_directories(nokia_test PRIVATE test_headers)

find_package(Threads REQUIRED)
target_link_libraries(nokia_test PRIVATE Threads::Threads)

find_package(GTest REQUIRED)
target_include_directories(nokia_test PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(nokia_test PRIVATE ${GTEST_LIBRARIES})
