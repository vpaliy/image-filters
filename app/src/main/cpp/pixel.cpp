//
// Created by Vasyl Paliy on 4/17/18.
//

#include "include/pixel.h"

inline pixel::pixel(int color) : color(color) {}

inline int pixel::R() {
    return (color & 0x00FF0000) >> 16;
}

inline int pixel::G() {
    return (color & 0x0000FF00) >> 8;
}

inline int pixel::B() {
    return color & 0x000000FF;
}

inline int pixel::alpha() {
    return (color & 0xFF000000) >> 24;
}

inline int pixel::fromRGB(int r, int g, int b) {
    return (255 << 24) | (r << 16) | (g << 8) | b;
}

inline int pixel::fromRGBA(int alpha, int r, int g, int b) {
    return (alpha << 24) | (r << 16) | (g << 8) | b;
}
