project(ffe)

add_subdirectory(lib/utf8cpp)

set(HEADER_FILES
        src/StrPathFinder.h src/AdjacencyMatrix.h)

set(SOURCE_FILES
        src/StrPathFinder.cpp src/AdjacencyMatrix.cpp)

add_library(ffe STATIC ${SOURCE_FILES} ${HEADER_FILES})

# utf8cpp header only library
target_include_directories(ffe PUBLIC lib/utf8cpp/src)