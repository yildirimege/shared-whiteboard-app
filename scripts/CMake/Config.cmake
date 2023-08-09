#-------------------------------------------------------------------------------------------------
#Build Configurations
#-------------------------------------------------------------------------------------------------

set(SHARED_WHITEBOARD_BUILD_SHARED ON CACHE BOOL "Build SW libraries static or not. Default value is shared now.")
if(SHARED_WHITEBOARD_BUILD_SHARED)
    message(STATUS "SharedWhiteboard BUILD TYPE: SHARED")
else()
    message(STATUS "SharedWhiteboard BUILD TYPE: STATIC")
endif()

#Set Unit Tests
set(SHARED_WHITEBOARD_BUILD_TESTS OFF CACHE BOOL "Build SharedWhiteboard unit test cases. Default value is off now.")
if(SHARED_WHITEBOARD_BUILD_TESTS)
    message(STATUS "SharedWhiteboard BUILD TESTS: ON")
else()
    message(STATUS "SharedWhiteboard BUILD TESTS: OFF")
endif()
