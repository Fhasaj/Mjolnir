cmake_minimum_required(VERSION 3.10)
project(Mjolnir)
# Find wxWidgets package
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Set the path to the Fonts folder (adjust the path as needed)
set(FONTS_FOLDER "${CMAKE_SOURCE_DIR}/Resources/Fonts")

# Copy all font files from the Fonts folder to the build directory
file(GLOB FONT_FILES "${FONTS_FOLDER}/*.ttf")
foreach(FONT_FILE ${FONT_FILES})
    get_filename_component(FONT_NAME ${FONT_FILE} NAME)
    add_custom_command(
        OUTPUT "${CMAKE_BINARY_DIR}/${FONT_NAME}"
        COMMAND ${CMAKE_COMMAND} -E copy "${FONT_FILE}" "${CMAKE_BINARY_DIR}/${FONT_NAME}"
        DEPENDS "${FONT_FILE}"
    )
endforeach()

# Include wxWidgets macros
include(${wxWidgets_USE_FILE})

# Source files
file(GLOB SOURCES
    Headers/*.h
    Sources/*.cpp
    Headers/CustomeUI/*.h
    Sources/CustomeUI/*.cpp
)

# Add executable
add_executable(Mjolnir ${SOURCES} "Sources/CustomeUI/Button.cpp" "Headers/CustomeUI/Button.h")

# Include headers
target_include_directories(Mjolnir PRIVATE ${wxWidgets_INCLUDE_DIRS})

# Link against wxWidgets libraries
target_link_libraries(Mjolnir PRIVATE ${wxWidgets_LIBRARIES})

## WINDOWS OS CONFIG OPTIONS
# Include .rc file in your project for Windows
if(WIN32)
    # Globing for all image files
    file(GLOB_RECURSE IMAGE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Resources/images/*.png
                                   ${CMAKE_CURRENT_SOURCE_DIR}/Resources/images/*.jpg
                                   ${CMAKE_CURRENT_SOURCE_DIR}/Resources/images/*.bmp)
    
    # Copy image files to build directory
    foreach(IMAGE_FILE ${IMAGE_FILES})
        file(COPY ${IMAGE_FILE} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    endforeach()
    
    # Set the resource file
    set(RESOURCE_FILE ${CMAKE_CURRENT_BINARY_DIR}/sample.res)
    
    # Generate the resource file
    file(WRITE ${RESOURCE_FILE} "")
    foreach(IMAGE_FILE ${IMAGE_FILES})
        file(APPEND ${RESOURCE_FILE} "IDR_${IMAGE_FILE} ${IMAGE_FILE}\n")
    endforeach()
    
    target_sources(Mjolnir PRIVATE ${RESOURCE_FILE})
    target_sources(Mjolnir PRIVATE Resources/mjolnir.rc)
    set_source_files_properties(${RESOURCE_FILE} PROPERTIES VS_TOOL_OVERRIDE "Resource Compiler")
    set_target_properties(Mjolnir PROPERTIES WIN32_EXECUTABLE TRUE)
endif()