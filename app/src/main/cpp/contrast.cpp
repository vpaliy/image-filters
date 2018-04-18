//
// Created by Vasyl Paliy on 4/17/18.
//

#include <algorithm>
#include "include/contrast.h"
#include "include/pixel.h"

inline contrast::contrast(int width, int height, int *pixels, int factor = 1)
        : filter(width, height, pixels), factor(factor) {}

inline void contrast::setFactor(int factor) {
    this->factor = factor;
}

inline int *contrast::process() {
    for (int i = 0; i < width * height; i++) {
        auto pixel = pixel(pixels[i]);
        int r = 128 + (pixel.R() - 128) * factor;
        int g = 128 + (pixel.G() - 128) * factor;
        int b = 128 + (pixel.B() - 128) * factor;

        r = std::min(255, std::max(0, r));
        g = std::min(255, std::max(0, g));
        b = std::min(255, std::max(0, b));

        pixels[i] = pixel::fromRGBA(pixel.alpha(), r, g, b);
    }
    return pixels;
}