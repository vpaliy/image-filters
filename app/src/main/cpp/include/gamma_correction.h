
#ifndef IMAGE_FILTERS_GAMMA_CORRECTION_H
#define IMAGE_FILTERS_GAMMA_CORRECTION_H

#include "filter.h"

namespace filters {
  class gamma_correction final : filter {
  public:
    struct options {
      int gamma;
      explicit options(int gamma) : gamma(gamma) {}
    };

    gamma_correction(width const &, height const &,
                      std::shared_ptr<pixels_wrapper>, options const &);

    virtual jintArray process() = 0;

  private:
    options _options;
  };

}
#endif
