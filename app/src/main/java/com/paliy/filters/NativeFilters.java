package com.paliy.filters;

public final class NativeFilters {
    public static native int[] brightness(int width, int height, int[] pixels, int factor);
    public static native int[] contrast(int width, int height, int[] pixels, int factor);
    public static native int[] gammaCorrection(int width, int height, int[] pixels, float gamma);
    public static native int[] gaussianBlur(int width, int height, int[] pixels, int gamma);
}
