
#include <cmath>
#include "include/filter.h"
#include "include/auto_array_ptr.h"
#include "include/gaussian_blur.h"

using namespace filters;
using row = std::vector<double>
using matrix = std::vector<row>


static

matrix getKernel() {
  //TODO
}

static double gaussian(double x, double mu, double sigma) {
  return std::exp(-(((x - mu) / (sigma)) * ((x - mu) / (sigma))) / 2.0);
}

gaussian_blur::gaussian_blur(width const &_width, height const &_height,
                             std::shared_ptr<pixels_wrapper> _pointer, options const &_options)
        : filter(_width, _height, _pointer), _options(_options) {}

jintArray gaussian_blur::process() {
  matrix kernel = getKernel();
  return _pointer->getArray();
}
