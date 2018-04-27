

#include <cmath>
#include "include/filter.h"
#include "include/gamma_correction.h"
#include "include/pixel.h"

using namespace filters;

gamma_correction::gamma_correction(width const &_width, height const &_height,
                                     std::shared_ptr<pixels_wrapper> _pointer,
                                     options const &_options)
        : filter(_width, _height, _pointer), _options(_options) {}

jintArray gamma_correction::process() {
  int *pixels = _pointer.get()->get();
  for (int i = 0; i < _size; i++) {
    pixel _pixel = pixel(pixels[i]);

    int r = (int) (255 * std::pow((_pixel.R() / 255), 1 / _options.gamma));
    int g = (int) (255 * std::pow((_pixel.G() / 255), 1 / _options.gamma));
    int b = (int) (255 * std::pow((_pixel.B() / 255), 1 / _options.gamma));

    pixels[i] = pixel::fromRGBA(_pixel.alpha(), r, g, b);
  }
  return _pointer->getArray();
}
