project(ffe)

set(HEADER_FILES
        src/StrPathFinder.cpp src/StrPathFinder.h)

set(SOURCE_FILES
        src/StrPathFinder.cpp src/StrPathFinder.h)

add_library(ffe STATIC ${SOURCE_FILES} ${HEADER_FILES})
