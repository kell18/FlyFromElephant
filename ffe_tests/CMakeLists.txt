cmake_minimum_required(VERSION 3.5)
project(ffe_tests)

add_subdirectory(lib/gtest-1.8)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}) # todo: try rm scnd arg
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

#configure_file(src/StrPathFinderTests.cpp.in src/StrPathFinderTests.cpp)

add_executable(ffeTests_run
        src/StrPathFinderTests.cpp src/AdjacencyMatrixTests.cpp)

target_link_libraries(ffeTests_run gtest gtest_main)
target_link_libraries(ffeTests_run ffe)
