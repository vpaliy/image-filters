

#ifndef IMAGE_FILTERS_CONTRAST_H
#define IMAGE_FILTERS_CONTRAST_H


#include "filter.h"

namespace filters {
  class contrast final : public filter {
  public:
    struct options {
      int factor;
      explicit options(int factor) : factor(factor) {}
    };

    contrast(width const &, height const &, std::shared_ptr<pixels_wrapper>, options const &);

    void setFactor(options const &);

    jintArray process() override;

  private:
    options _options;
  };
}


#endif //IMAGE_FILTERS_CONTRAST_H
