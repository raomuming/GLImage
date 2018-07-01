//
// Created by Eric Rao on 01/07/2018.
//

#ifndef GLIMAGE_COMMONDEFINE_H
#define GLIMAGE_COMMONDEFINE_H

#include <android/log.h>

#define LOG_TAG "GLIMAGE-LIB"
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

typedef enum BufferFormat {
    FORMAT_RGB_INT8,
    FORMAT_RGB_INT16,
    FORMAT_RGB_FLOAT32,
    FORMAT_RGBA_INT8,
    FORMAT_RGBA_INT16,
    FORMAT_RGBA_FLOAT32,
} BufferFormat;


#endif //GLIMAGE_COMMONDEFINE_H
