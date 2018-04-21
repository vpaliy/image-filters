
#include "brightness.h"
#include "pixel.h"
#include <algorithm>

brightness::brightness(width _width, height _height,
                       std::shared_ptr<pixels_wrapper> _pointer, options _options)
        : filter(_width, _height, _pointer), _options(_options) {}

void brightness::setFactor(options _options) {
  this->_options = _options;
}

jintArray brightness::process() {
  int *pixels = _pointer.get()->get();
  for (int i = 0; i < _size; i++) {
    auto _pixel = pixel(pixels[i]);
    int r = _pixel.R() + _options.factor;
    int g = _pixel.G() + _options.factor;
    int b = _pixel.B() + _options.factor;

    r = std::min(255, std::max(0, r));
    g = std::min(255, std::max(0, g));
    b = std::min(255, std::max(0, b));

    pixels[i] = pixel::fromRGBA(_pixel.alpha(), r, g, b);
  }
  return _pointer.get()->copy(_size);
}