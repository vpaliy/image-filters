package com.paliy.filters;

import android.graphics.Bitmap;

public class ContrastFilter extends ImageFilter {
    private int factor = 1;

    public ContrastFilter(Bitmap bitmap) {
        super(bitmap);
    }

    public ContrastFilter(Bitmap bitmap, int factor) {
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
    public Bitmap process() {
        final int[] pixels = NativeFilters.contrast(getWidth(), getHeight(), getPixels(), factor);
        return Bitmap.createBitmap(pixels, getWidth(), getHeight(), Bitmap.Config.ARGB_8888);
    }
}
