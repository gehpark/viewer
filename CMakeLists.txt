project(viewer)

###############
# CMAKE FLAGS #
###############

cmake_minimum_required(VERSION 2.6)
cmake_policy(VERSION 2.6)

set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake )

if(WIN32)
    add_definitions( "/W3 /D_CRT_SECURE_NO_WARNINGS /wd4503 /nologo" )
endif(WIN32)

############
# Packages #
############

set( QT_USE_QTXML     TRUE )
set( QT_USE_QTMAIN    TRUE )
set( QT_USE_QTSCRIPT  TRUE )
set( QT_USE_QTOPENGL  TRUE )

find_package(Qt4)
find_package(OpenGL)

#########
# Files #
#########

set( HDRS console_color.h random.h timer.h window.h glviewer.h)

set( SRCS window.cpp glviewer.cpp main.cpp)

set( MOCS moc_glviewer.cxx moc_window.cxx)

set( UIS window.ui )

#########
# Build #
#########

SET(CMAKE_CXX_FLAGS "-g -L\"/Volumes/Macintosh\ HD/Applications/MATLAB_R2012a.app/bin/maci64/\"")

include_directories(BEFORE . ./build)
include(${QT_USE_FILE})
include_directories(${GLUT_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})

# UI files
qt4_wrap_ui( DT_UI_FILES ${UIS} )

# MOC files
qt4_generate_moc( glviewer.h moc_glviewer.cxx )
qt4_generate_moc( window.h moc_window.cxx )

# Executable
add_executable( ${PROJECT_NAME} ${SRCS} ${MOCS} ${DT_UI_FILES} ${DT_RESOURCE_FILES} )

# Link with Qt
target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} )

# Link with Glut and OpenGL
target_link_libraries( ${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES}  )
target_link_libraries( ${PROJECT_NAME} libeng.dylib )
