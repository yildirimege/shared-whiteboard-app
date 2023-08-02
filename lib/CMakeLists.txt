# Set the library target
set(SOURCES
    src/Engine/SharedWhiteboard.cpp
)

add_library(whiteboard ${SOURCES})

# Include the 'src' directory to allow #include "whiteboard.h"
target_include_directories(whiteboard PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")


