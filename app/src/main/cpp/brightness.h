//
// Created by Vasyl Paliy on 4/16/18.
//

#ifndef IMAGE_FILTERS_BRIGHTNESS_H
#define IMAGE_FILTERS_BRIGHTNESS_H

#include "filter.h"

class brightness final : public filter {
private:
    int factor;
public:
    brightness(int, int, int *, int = 1);

    int *process() override;

    void setFactor(int factor);
};


#endif //IMAGE_FILTERS_BRIGHTNESS_H
