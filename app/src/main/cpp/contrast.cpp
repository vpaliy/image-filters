
#include <algorithm>
#include "contrast.h"
#include "pixel.h"

using namespace filters;

contrast::contrast(width const &_width, height const &_height,
                   std::shared_ptr<pixels_wrapper> _pointer, options const &_options)
        : filter(_width, _height, _pointer), _options(_options) {}

void contrast::setFactor(options const &options_) {
  this->_options = options_;
}

jintArray contrast::process() {
  int *pixels = _pointer.get()->get();
  for (int i = 0; i < _size; i++) {
    pixel _pixel = pixel(pixels[i]);
    int r = 128 + (_pixel.R() - 128) * _options.factor;
    int g = 128 + (_pixel.G() - 128) * _options.factor;
    int b = 128 + (_pixel.B() - 128) * _options.factor;

    r = std::min(255, std::max(0, r));
    g = std::min(255, std::max(0, g));
    b = std::min(255, std::max(0, b));

    pixels[i] = pixel::fromRGBA(_pixel.alpha(), r, g, b);
  }
  return _pointer.get()->copy(_size);
}