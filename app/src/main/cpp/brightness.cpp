//
// Created by Vasyl Paliy on 4/16/18.
//

#include "include/brightness.h"
#include "include/pixel.h"
#include <algorithm>

inline brightness::brightness(int width, int height, int *pixels, int factor = 1)
        : filter(width, height, pixels), factor(factor) {}

inline void brightness::setFactor(int factor) {
    this->factor = factor;
}

int *brightness::process() {
    for (int i = 0; i < width * height; i++) {
        auto pixel = pixel(pixels[i]);
        int r = pixel.R() + factor;
        int g = pixel.G() + factor;
        int b = pixel.B() + factor;

        r = std::min(255, std::max(0, r));
        g = std::min(255, std::max(0, g));
        b = std::min(255, std::max(0, b));

        pixels[i] = pixel::fromRGBA(pixel.alpha(), r, g, b);
    }
    return pixels;
}