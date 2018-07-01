package com.linkedu.glimage.utils;

public abstract class TextureRenderer {

    public static class Viewport {
        public int x, y;
        public int width, height;
        public Viewport() {}

        public Viewport(int _x, int _y, int _width, int _height) {
            x = _x;
            y = _y;
            width = _width;
            height = _height;
        }
    }
}
