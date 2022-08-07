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

#=================== INCLUSION OF Project Files ====================#
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(IEC61850_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libiec61850/include/libiec61850")
#set(LIB_DIR "${CMAKE_SOURCE_DIR}/libiec61850/lib")
#set(BIN_DIR "${CMAKE_SOURCE_DIR}/libiec61850/bin")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})
include_directories(${IEC61850_INCLUDE_DIR})

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
target_link_libraries(MY_PROJECT Qt6::Widgets)
#target_link_libraries(MY_PROJECT ${LIB_DIR})
#target_link_libraries(MY_PROJECT ${BIN_DIR})


#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\build;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\build\
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\forms;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\include;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\src;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\lib\libiec61850\src\iec61850\inc;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\lib\libiec61850\src\iec61850\inc_private;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\lib\libiec61850\src\common\inc;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\lib\libiec61850\src\goose;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\lib\libiec61850\src\sampled_values;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\lib\libiec61850\src\mms\inc;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\lib\libiec61850\src\mms\inc_private;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\lib\libiec61850\src\mms\iso_mms\asn1c;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\lib\libiec61850\src\logging;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\lib\libiec61850\hal\inc;
#C:\TEMP\Code\IEC61850_Qt\examples\QtWidgets\Qt6CMake-main\lib\libiec61850\config;
#MY_PROJECT_autogen\include_Release;%(AdditionalIncludeDirectories)
