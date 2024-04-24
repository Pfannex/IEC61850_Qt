cmake_minimum_required(VERSION 3.14)

if (WIN32)
    project(MY_PROJECT LANGUAGES CXX)
elseif(UNIX)
    project(MY_PROJECT)
endif()

set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Network Widgets)

#find_package(libiec61850 REQUIRED)
message("found!!")

#=================== INCLUSION OF Project Files ====================#
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(IEC61850_INCLUDE_DIR "C:/Program Files/libiec61850/include/libiec61850")
set(LIB_DIR "C:/Program Files/libiec61850/lib")
#set(IEC61850_INCLUDE_DIR "T:/Coding/repos/libs/iec61850/include/libiec61850")
#set(LIB_DIR "T:/Coding/repos/libs/iec61850/lib")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})



file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${FORMS_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
    "${IEC61850_INCLUDE_DIR}/*.h"
)

#=================== SETUP EXECTUABLE ====================#
# Enable debug logging on RELWITHDEBINFO configuration
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>
)

# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

# Add the executable
if (WIN32) 
    add_executable(MY_PROJECT WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(MY_PROJECT ${SOURCES})
endif()

# Add the target includes for MY_PROJECT 
target_include_directories(MY_PROJECT PRIVATE ${FORMS_DIR})
target_include_directories(MY_PROJECT PRIVATE ${INCLUDE_DIR})
target_include_directories(MY_PROJECT PRIVATE ${SOURCE_DIR})
target_include_directories(MY_PROJECT PRIVATE ${IEC61850_INCLUDE_DIR})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(MY_PROJECT ${LIB_DIR}/iec61850.lib )
target_link_libraries(MY_PROJECT ${LIB_DIR}/hal.lib )
#target_link_libraries(MY_PROJECT ${LIB_DIR}/hal-shared.lib )
target_link_libraries(MY_PROJECT 
    Qt6::Widgets
    Qt6::Core
    Qt6::Gui
    Qt6::Network
    Qt6::Widgets
)