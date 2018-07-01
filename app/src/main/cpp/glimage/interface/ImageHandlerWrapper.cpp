//
// Created by Eric Rao on 01/07/2018.
//

#include "ImageHandlerWrapper.h"
#include "ImageHandlerAndroid.h"

using namespace glimage;

extern "C"
{

JNIEXPORT jlong JNICALL Java_com_linkedu_glimage_nativeport_ImageHandler_nativeCreatedHandler
        (JNIEnv*, jobject)
{
    ImageHandlerAndroid* handler = new ImageHandlerAndroid();
    return (jlong)handler;
}

JNIEXPORT jboolean JNICALL Java_com_linkedu_glimage_nativeport_ImageHandler_nativeInitWithBitmap
        (JNIEnv* env, jobject, jlong addr, jobject bmp)
{
    ImageHandlerAndroid* handler = (ImageHandlerAndroid*)addr;
    return handler->initWithBitmap(env, bmp, true);
}

}