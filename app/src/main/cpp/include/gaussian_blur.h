
#ifndef IMAGE_FILTERS_GAUSSIAN_BLUR_H
#define IMAGE_FILTERS_GAUSSIAN_BLUR_H

#include <vector>
#include "filter.h"

namespace filters {
  class gaussian_blur final : filter {
  public:
    struct options {
      double sigma;
      explicit options(double sigma) : sigma(sigma) {}
    };

    gaussian_blur(width const &,
                  height const &,
                  std::shared_ptr<pixels_wrapper>,
                  options const &);

    virtual jintArray process() = 0;

  private:
    options _options;
  };
}
#endif
