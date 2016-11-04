project(ffe_tests)

add_subdirectory(lib/gtest-1.7.0)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(ffeTests_run
        src/StringPathFinder_check.cpp)

target_link_libraries(ffeTests_run gtest gtest_main)
target_link_libraries(ffeTests_run ffe)
