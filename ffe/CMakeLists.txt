project(ffe)

add_subdirectory(lib/utf8cpp)

set(HEADER_FILES
        src/StrPathFinder.cpp src/StrPathFinder.h src/AdjacencyMatrix.cpp src/AdjacencyMatrix.h)

set(SOURCE_FILES
        src/StrPathFinder.cpp src/StrPathFinder.h src/AdjacencyMatrix.cpp src/AdjacencyMatrix.h)

add_library(ffe STATIC ${SOURCE_FILES} ${HEADER_FILES})

### Link utf8cpp lib
target_include_directories(ffe PUBLIC lib/utf8cpp/src)
target_link_libraries(ffe utf8cpp)