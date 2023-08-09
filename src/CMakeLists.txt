## List your source files here
#set(SRC_FILES
#    UI/LoginWindow.cpp
#)

## List your header files here
#set(HEADER_FILES
#    UI/LoginWindow.h
#)

## Create a library target
#add_library(SharedWhiteboardLib ${SRC_FILES} ${HEADER_FILES}
#    Engine/Engine.h
#    Engine/Engine.cpp
#    Managers/WindowManager.h
#    Managers/WindowManager.cpp
#    Managers/CommunicationManager.cpp
#    Managers/CommunicationManager.h)

## Set include directories for the library
#target_include_directories(SharedWhiteboardLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(app)
