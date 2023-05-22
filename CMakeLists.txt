cmake_minimum_required(VERSION 3.5)

project(3DViewer_v1.0 VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)

set(QT_OPENGL_WIDGETS_MODULE "OpenGLWidgets")

if(QT_VERSION_MAJOR EQUAL 5)
    find_package(Qt5OpenGLWidgets QUIET)
    if(NOT Qt5OpenGLWidgets_FOUND)
        set(QT_OPENGL_WIDGETS_MODULE "OpenGL")
    endif()
endif()

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets ${QT_OPENGL_WIDGETS_MODULE} REQUIRED)

set (QRC_FILES resources.qrc)

set(PROJECT_SOURCES
        src/main.cc
        src/libobj/obj_data.c
        src/libobj/obj_data.h
        src/libobj/affine_transform.c
        src/libobj/affine_transform.h
        src/libobj/obj_loader.cc
        src/libobj/obj_loader.h
        src/libgif/gif.cc
        src/libgif/gif.h
        src/viewer/viewer.cc
        src/viewer/viewer.h
        src/viewer/viewer.ui
)

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    add_compile_definitions(GL_SILENCE_DEPRECATION)
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(3DViewer_v1.0
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES} ${QRC_FILES}
    )
else()
    add_executable(3DViewer_v1.0
            ${PROJECT_SOURCES} ${QRC_FILES})
endif()

target_link_libraries(3DViewer_v1.0 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                            Qt${QT_VERSION_MAJOR}::${QT_OPENGL_WIDGETS_MODULE} OpenGL::GL)

target_compile_options(3DViewer_v1.0 PRIVATE -Wall -Werror -Wextra -O1)

set_target_properties(3DViewer_v1.0 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3DViewer_v1.0)
endif()
