
#include "include/pixel.h"

pixel::pixel(int color) : color(color) {}

int pixel::R() {
  return (color & 0x00FF0000) >> 16;
}

int pixel::G() {
  return (color & 0x0000FF00) >> 8;
}

int pixel::B() {
  return color & 0x000000FF;
}

int pixel::alpha() {
  return (color & 0xFF000000) >> 24;
}

int pixel::fromRGB(int r, int g, int b) {
  return (255 << 24) | (r << 16) | (g << 8) | b;
}

int pixel::fromRGBA(int alpha, int r, int g, int b) {
  return (alpha << 24) | (r << 16) | (g << 8) | b;
}
