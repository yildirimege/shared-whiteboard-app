# -------------------------------------------------------------------------------------------------
# Application
# -------------------------------------------------------------------------------------------------
project(SharedWhiteboardApp VERSION ${VER_MAJ}.${VER_MIN}.${VER_BID} LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/Users/egeyildirim/Qt/6.6.0/macos/lib/cmake")

# -------------------------------------------------------------------------------------------------
# Find Packages
# -------------------------------------------------------------------------------------------------
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Gui REQUIRED)
find_package(Boost COMPONENTS system thread REQUIRED)



# -------------------------------------------------------------------------------------------------
# HEADERS & SOURCES
# -------------------------------------------------------------------------------------------------
# Header files *.h
set(HEADERS
    "${CMAKE_CURRENT_LIST_DIR}/Engine/Engine.h"

    "${CMAKE_CURRENT_LIST_DIR}/UI/LoginWindow.h"
    "${CMAKE_CURRENT_LIST_DIR}/UI/WaitingWindow_client.h"
    "${CMAKE_CURRENT_LIST_DIR}/UI/WaitingWindow_server.h"


    "${CMAKE_CURRENT_LIST_DIR}/Managers/CommunicationManager.h"
    "${CMAKE_CURRENT_LIST_DIR}/Managers/WindowManager.h"
)
# Source files *.cpp
set(SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/main.cpp"

    "${CMAKE_CURRENT_LIST_DIR}/Engine/Engine.cpp"

    "${CMAKE_CURRENT_LIST_DIR}/UI/LoginWindow.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UI/WaitingWindow_client.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UI/WaitingWindow_server.cpp"

    "${CMAKE_CURRENT_LIST_DIR}/Managers/CommunicationManager.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Managers/WindowManager.cpp"
)

# Resource files *.qrc
set(RESOURCES
    ${CMAKE_SOURCE_DIR}/res/200.gif
)

# Update qml import path in environment
#add_qml_dir("${CMAKE_CURRENT_LIST_DIR}/ui/")


# -------------------------------------------------------------------------------------------------
# Add platform based headers and sources
# -------------------------------------------------------------------------------------------------
if(WIN32)
    list(APPEND HEADERS)
    list(APPEND SOURCES)
elseif(APPLE)

elseif(UNIX AND NOT )

endif()

# -------------------------------------------------------------------------------------------------
# Project Definition
# -------------------------------------------------------------------------------------------------
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${HEADERS}
        ${SOURCES}
        ${RESOURCES}
        UI/DrawingCanvas.h
        UI/DrawingCanvas.cpp
        Common/common.h
        Client/client.h
        Client/packet.h
        Client/client.cpp
        Client/packet.cpp
        Server/server.h
        Server/packet.h
        Server/session.h
        Server/packet.cpp
        Server/server.cpp
        Server/session.cpp
        Common/utilities.cpp
        Common/message.hpp
        Common/logger.hpp


    )
else()
    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED
            ${HEADERS}
            ${SOURCES}
            ${RESOURCES}
        )
else()
    add_executable(${PROJECT_NAME}
        ${HEADERS}
        ${SOURCES}
        ${RESOURCES}
    )
endif()
endif()

# -------------------------------------------------------------------------------------------------
# Project Icon
# -------------------------------------------------------------------------------------------------
if(APPLE)
    #set(${PROJECT_NAME}_ICON temp.icns)
elseif(WIN32)
    #set(${PROJECT_NAME}_ICON temp.ico)
elseif(UNIX AND NOT APPLE)
    #set(${PROJECT_NAME}_ICON temp.png)
endif()

#set(ICON_FILE ${CMAKE_SOURCE_DIR}/Scripts/Platform/Windows/${${PROJECT_NAME}_ICON})
#target_sources(${PROJECT_NAME} PRIVATE ${ICON_FILE})

# -------------------------------------------------------------------------------------------------
# Application Bundle
# -------------------------------------------------------------------------------------------------
#if(APPLE)
#   set_source_files_properties(
#       ${ICON_FILE}
#       PROPERTIES MACOSX_PACKAGE_LOCATION "Resources"
#       )

#   set_target_properties(${PROJECT_NAME} PROPERTIES
#       MACOSX_BUNDLE true
#       MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/Scripts/Platform/macOS/Info.plist.in
#       MACOSX_BUNDLE_ICON_FILE ${${PROJECT_NAME}_ICON}
#       INSTALL_RPATH "@loader_path/../Frameworks"
#       INSTALL_RPATH_USE_LINK_PATH TRUE
#       )

#elseif(WIN32)
#   set_target_properties(${PROJECT_NAME} PROPERTIES
#       WIN32_EXECUTABLE true
#       )

#   set(RESOURCE_FILE "${CMAKE_BINARY_DIR}/TiraApp.rc")
#   configure_file("${CMAKE_SOURCE_DIR}/Scripts/Platform/Windows/resource_template.rc.in" "${RESOURCE_FILE}")

#   ENABLE_LANGUAGE(RC)
#   target_sources(${PROJECT_NAME} PRIVATE ${RESOURCE_FILE})

#elseif(UNIX AND NOT APPLE)
#   set(RESOURCE_FILE "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.desktop")
#   configure_file("${CMAKE_SOURCE_DIR}/Scripts/Platform/Linux/gnome_dekstop_entry.in" "${RESOURCE_FILE}")
#endif()

# -------------------------------------------------------------------------------------------------
# Link Libraries
# -------------------------------------------------------------------------------------------------
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Gui
)


target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    ${Boost_LIBRARIES}
)

# -------------------------------------------------------------------------------------------------
# Include Directories
# -------------------------------------------------------------------------------------------------
target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/app
    ${Boost_INCLUDE_DIRS}
)

# -------------------------------------------------------------------------------------------------
# Compile Definitions
# -------------------------------------------------------------------------------------------------
target_compile_definitions(${PROJECT_NAME}
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# -------------------------------------------------------------------------------------------------
# Deployment Configurations
# -------------------------------------------------------------------------------------------------
#redirectOutputPath(${PROJECT_NAME})


set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER app.yildirimege.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    #qt_import_qml_plugins(${PROJECT_NAME})
    qt_finalize_executable(${PROJECT_NAME})
endif()

