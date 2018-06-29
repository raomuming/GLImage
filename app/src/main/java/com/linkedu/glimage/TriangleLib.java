package com.linkedu.glimage;

public class TriangleLib {
    static {
        System.loadLibrary("triangle-lib");
    }

    public static native boolean init();

    public static native void resize(int width, int height);

    public static native void step();
}
