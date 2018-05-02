
#ifndef IMAGE_FILTERS_GAMMA_CORRECTION_H
#define IMAGE_FILTERS_GAMMA_CORRECTION_H

#include "filter.h"

namespace filters {
  class gamma_correction final : filter {
  public:
    struct options {
      float gamma;
      explicit options(float gamma) : gamma(gamma) {}
    };

    gamma_correction(width const &, height const &,
                      std::shared_ptr<pixels_wrapper>, options const &);

    jintArray process() override;

  private:
    options _options;
  };

}
#endif
