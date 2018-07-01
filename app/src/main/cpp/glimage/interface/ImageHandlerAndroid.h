//
// Created by Eric Rao on 01/07/2018.
//

#ifndef GLIMAGE_IMAGEHANDLERANDROID_H
#define GLIMAGE_IMAGEHANDLERANDROID_H

#include <jni.h>
#include "../include/ImageHandler.h"

namespace glimage {
    class ImageHandlerAndroid : public ImageHandler {
    public:
        ImageHandlerAndroid();
        ~ImageHandlerAndroid();

        bool initWithBitmap(JNIEnv* env, jobject bitmap, bool enableReversion = false);
    };
}

#endif //GLIMAGE_IMAGEHANDLERANDROID_H
