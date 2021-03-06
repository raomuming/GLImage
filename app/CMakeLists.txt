
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-rtti -fno-exceptions -Wall")

if (${ANDROID_PLATFORM_LEVEL} LESS 11)
    message(FATAL_ERROR "OpenGL 2 is not supported before API level 11 (currently using ${ANDROID_PLATFORM_LEVEL}).")
    return()
elseif (${ANDROID_PLATFORM_LEVEL} LESS 18)
    add_definitions("-DDYNAMIC_ES3")
    set(OPENGL_LIB GLESv2)
else ()
    set(OPENGL_LIB GLESv3)
endif (${ANDROID_PLATFORM_LEVEL})

add_library( triangle-lib
             SHARED
             src/main/cpp/triangle-lib.cpp)

target_link_libraries(triangle-lib
                      ${OPENGL_LIB}
                      android
                      EGL
                      log
                      m)


add_library(glimage-lib
            SHARED
            src/main/cpp/glimage/common/ImageHandler.cpp
            src/main/cpp/glimage/interface/ImageHandlerWrapper.cpp
            src/main/cpp/glimage/interface/ImageHandlerAndroid.cpp)


target_link_libraries(glimage-lib
                      ${OPENGL_LIB}
                      android
                      EGL
                      log
                      m)