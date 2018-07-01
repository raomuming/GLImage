package com.linkedu.glimage.nativeport;

import android.graphics.Bitmap;

public class ImageHandler {
    static {
        System.loadLibrary("glimage-lib");
    }

    protected long mNativeAddress;

    public ImageHandler() {
        mNativeAddress = nativeCreateHandler();
    }

    public boolean initWithBitmap(Bitmap bmp) {
        if (bmp == null)
            return false;

        if (bmp.getConfig() != Bitmap.Config.ARGB_8888) {
            bmp = bmp.copy(Bitmap.Config.ARGB_8888, false);
        }

        return nativeInitWithBitmap(mNativeAddress, bmp);
    }

    public boolean initWithSize(int width, int height){
        return true;
    }

    public Bitmap getResultBitmap() {
        return null;
    }

    public void setDrawerRotation(float rad) {

    }

    public void setDrawerFlipScale(float x, float y) {

    }

    public void setFilterWithConfig(String config) {

    }

    public void setFilterIntensity(float intensity) {

    }

    public void setFilterIntensity(float intensity, boolean shouldProcess) {

    }

    public boolean setFilterIntensityAtIndex(float intensity, int index, boolean shouldProcess) {
        return true;
    }

    public void drawResult() {

    }

    public void bindTargetFBO() {

    }

    public void setAsTarget() {

    }

    public void swapBufferFBO() {

    }

    public void revertImage() {

    }

    public void processFilters() {

    }

    public void processWithFilter(long filterAddress) {

    }

    public void release() {

    }

    public void setFilterWithAddress(long filter) {

    }

    // native method
    protected native long nativeCreateHandler();

    protected native boolean nativeInitWithBitmap(long holder, Bitmap bmp);
}
