//
// Created by Vasyl Paliy on 4/17/18.
//

#include <algorithm>
#include "contrast.h"
#include "pixel.h"

contrast::contrast(int width, int height, int *pixels, int factor )
        : filter(width, height, pixels), factor(factor) {}

void contrast::setFactor(int factor) {
    this->factor = factor;
}

int *contrast::process() {
    for (int i = 0; i < width * height; i++) {
        pixel _pixel = pixel(pixels[i]);
        int r = 128 + (_pixel.R() - 128) * factor;
        int g = 128 + (_pixel.G() - 128) * factor;
        int b = 128 + (_pixel.B() - 128) * factor;

        r = std::min(255, std::max(0, r));
        g = std::min(255, std::max(0, g));
        b = std::min(255, std::max(0, b));

        pixels[i] = pixel::fromRGBA(_pixel.alpha(), r, g, b);
    }
    return pixels;
}