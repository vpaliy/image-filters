//
// Created by Vasyl Paliy on 4/16/18.
//

#include "brightness.h"
#include "pixel.h"
#include <algorithm>

brightness::brightness(int width, int height, int *pixels, int factor )
        : filter(width, height, pixels), factor(factor) {}

void brightness::setFactor(int factor) {
    this->factor = factor;
}

int *brightness::process() {
    for (int i = 0; i < width * height; i++) {
        auto _pixel = pixel(pixels[i]);
        int r = _pixel.R() + factor;
        int g = _pixel.G() + factor;
        int b = _pixel.B() + factor;

        r = std::min(255, std::max(0, r));
        g = std::min(255, std::max(0, g));
        b = std::min(255, std::max(0, b));

        pixels[i] = pixel::fromRGBA(_pixel.alpha(), r, g, b);
    }
    return pixels;
}