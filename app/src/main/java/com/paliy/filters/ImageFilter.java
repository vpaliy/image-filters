package com.paliy.filters;

import android.graphics.Bitmap;

public abstract class ImageFilter {

    private static final String FILTERS_LIB = "filters-lib";

    private final Bitmap bitmap;

    ImageFilter(Bitmap bitmap) {
        this.bitmap = bitmap;
    }

    protected int[] getPixels() {
        final int width = bitmap.getWidth();
        final int height = bitmap.getHeight();
        final int[] pixels = new int[width * height];
        bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
        return pixels;
    }

    protected int getWidth() {
        return bitmap.getWidth();
    }

    protected int getHeight() {
        return bitmap.getHeight();
    }

    public abstract ImageFilter setBitmap(Bitmap bitmap);

    static {
        System.loadLibrary(FILTERS_LIB);
    }

    public abstract Bitmap process();
}
