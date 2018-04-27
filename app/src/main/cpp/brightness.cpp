
#include "include/brightness.h"
#include "include/pixel.h"
#include <algorithm>

using namespace filters;

brightness::brightness(width const &_width, height const &_height,
                       std::shared_ptr<pixels_wrapper> _pointer, options const &_options)
        : filter(_width, _height, _pointer), _options(_options) {}

void brightness::setFactor(options const &_options) {
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
  return _pointer->getArray();
}