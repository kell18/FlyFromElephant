cmake_minimum_required(VERSION 3.1)
project(FlyFromElephant)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(ffe_run ${SOURCE_FILES})

include_directories(ffe)

add_subdirectory(ffe)
add_subdirectory(ffe_tests)

target_link_libraries(ffe_run ffe)


#if ($ENV{CLION_IDE})
#    message("Call cmake command from the CLion IDE")
#    set(CALENDAR_PATH_VAR "test")
#    set(CALENDAR_DIR_VAR "test")
#endif ()
