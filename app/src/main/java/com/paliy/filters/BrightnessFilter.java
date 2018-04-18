package com.paliy.filters;


import android.graphics.Bitmap;

public final class BrightnessFilter extends ImageFilter {
    private int factor = 1;

    public BrightnessFilter(Bitmap bitmap) {
        super(bitmap);
    }

    public BrightnessFilter(Bitmap bitmap, int factor) {
        super(bitmap);
        this.factor = factor;
    }

    public void setFactor(int factor) {
        this.factor = factor;
    }

    public int getFactor() {
        return factor;
    }

    @Override
    public ImageFilter setBitmap(Bitmap bitmap) {
        return new BrightnessFilter(bitmap, factor);
    }

    @Override
    public Bitmap process() {
        final int[] pixels = NativeFilters.brightness(getWidth(), getHeight(), getPixels(), factor);
        return Bitmap.createBitmap(pixels, getWidth(), getHeight(), Bitmap.Config.ARGB_8888);
    }
}
