
#ifndef IMAGE_FILTERS_BRIGHTNESS_H
#define IMAGE_FILTERS_BRIGHTNESS_H

#include "filter.h"

class brightness final : public filter {
public:
  struct options {
    int factor;
    explicit options(int factor)
            : factor(factor) {}
  };

  brightness(width, height, std::shared_ptr<pixels_wrapper>, options);

  void setFactor(options);

  jintArray process() override;

private:
  options _options;
};

#endif
