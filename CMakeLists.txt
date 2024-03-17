cmake_minimum_required(VERSION 3.10)
project(Mjolnir)
# Find wxWidgets package
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Include wxWidgets macros
include(${wxWidgets_USE_FILE})

# Source files
file(GLOB SOURCES
    Headers/*.h
    Sources/*.cpp
)

# Add executable
add_executable(Mjolnir ${SOURCES})

# Include headers
target_include_directories(Mjolnir PRIVATE ${wxWidgets_INCLUDE_DIRS})

# Link against wxWidgets libraries
target_link_libraries(Mjolnir PRIVATE ${wxWidgets_LIBRARIES})

## WINDOWS OS CONFIG OPTIONS
# Include .rc file in your project for Windows
if(WIN32)
    set(RESOURCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Resources/sample.res)
    target_sources(Mjolnir PRIVATE ${RESOURCE_FILE})
    set_source_files_properties(${RESOURCE_FILE} PROPERTIES VS_TOOL_OVERRIDE "Resource Compiler")
    set_target_properties(Mjolnir PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

# Set the resource file as a custom command to be compiled by Visual Studio
if(WIN32)
    set_source_files_properties(${RESOURCE_FILE} PROPERTIES VS_TOOL_OVERRIDE "Resource Compiler")
endif()

