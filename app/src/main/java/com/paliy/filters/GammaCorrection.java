package com.paliy.filters;

import android.graphics.Bitmap;

public class GammaCorrection extends ImageFilter {

    private final float gammaFactor;

    public GammaCorrection(Bitmap bitmap) {
        this(bitmap, 0);
    }

    public GammaCorrection(Bitmap bitmap, float gammaFactor) {
        super(bitmap);
        this.gammaFactor = gammaFactor;
    }


    @Override
    public ImageFilter setBitmap(Bitmap bitmap) {
        return new GammaCorrection(bitmap, gammaFactor);
    }

    @Override
    public Bitmap process() {
        final int[] pixels = NativeFilters.gammaCorrection(getWidth(), getHeight(), getPixels(), gammaFactor);
        return Bitmap.createBitmap(pixels, getWidth(), getHeight(), Bitmap.Config.ARGB_8888);
    }
}
