//
// Created by Eric Rao on 01/07/2018.
//

#ifndef GLIMAGE_IMAGEHANDLERWRAPPER_H
#define GLIMAGE_IMAGEHANDLERWRAPPER_H

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong JNICALL Java_com_linkedu_glimage_nativeport_ImageHandler_nativeCreatedHandler
        (JNIEnv*, jobject);


JNIEXPORT jboolean JNICALL Java_com_linkedu_glimage_nativeport_ImageHandler_nativeInitWithBitmap
        (JNIEnv*, jobject, jlong, jobject);

#ifdef __cplusplus
}
#endif

#endif //GLIMAGE_IMAGEHANDLERWRAPPER_H
