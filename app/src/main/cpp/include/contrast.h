//
// Created by Vasyl Paliy on 4/17/18.
//

#ifndef IMAGE_FILTERS_CONTRAST_H
#define IMAGE_FILTERS_CONTRAST_H


#include "filter.h"

class contrast final : public filter {
private:
    int factor;
public:
    contrast(int, int, int *, int = 1);

    void setFactor(int);

    int* process() override ;
};


#endif //IMAGE_FILTERS_CONTRAST_H
