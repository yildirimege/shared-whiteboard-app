# Specify the target executable and its source files
set(SOURCES
    src/main.cpp
)

add_executable(MyWhiteboardAppApp ${SOURCES})

# Link the app executable with the 'whiteboard' library
target_link_libraries(MyWhiteboardAppApp PRIVATE whiteboard)
