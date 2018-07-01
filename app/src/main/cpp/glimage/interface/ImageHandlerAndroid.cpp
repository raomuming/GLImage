//
// Created by Eric Rao on 01/07/2018.
//

#include "ImageHandlerAndroid.h"
#include "../include/CommonDefine.h"

#include <android/bitmap.h>

namespace glimage {
    ImageHandlerAndroid::ImageHandlerAndroid() {}

    ImageHandlerAndroid::~ImageHandlerAndroid() {}

    bool ImageHandlerAndroid::initWithBitmap(JNIEnv* env, jobject bitmap, bool enableReversion) {
        AndroidBitmapInfo info;
        int ret = AndroidBitmap_getInfo(env, bitmap, &info);

        if (ret < 0) {
            ALOGE("AndroidBitmap_getInfo() failed! error=%d", ret);
            return false;
        }

        if (info.format != ANDROID_BITMAP_FORMAT_RGBA_8888) {
            ALOGE("Bitmap format is not RGBA_8888");
            return false;
        }

        char* row;
        ret = AndroidBitmap_lockPixels(env, bitmap, (void**)&row);

        if (ret < 0) {
            ALOGE("AndroidBitmap_lockPixels() failed! error=%d", ret);
            return false;
        }

        bool flag = initWithRawBufferData(row, info.width, info.height, FORMAT_RGBA_INT8, enableReversion);

        AndroidBitmap_unlockPixels(env, bitmap);

        return flag;
    }
}