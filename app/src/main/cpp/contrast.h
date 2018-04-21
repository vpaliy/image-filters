

#ifndef IMAGE_FILTERS_CONTRAST_H
#define IMAGE_FILTERS_CONTRAST_H


#include "filter.h"

class contrast final : public filter {
public:
  struct options {
    int factor;
    explicit options(int factor)
            : factor(factor) {}
  };

  contrast(width, height, std::shared_ptr<pixels_wrapper>, options);

  void setFactor(options);

  jintArray process() override;

private:
  options _options;
};


#endif //IMAGE_FILTERS_CONTRAST_H
