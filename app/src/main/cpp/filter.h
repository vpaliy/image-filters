//
// Created by Vasyl Paliy on 4/16/18.
//

#ifndef IMAGE_FILTERS_FILTER_H
#define IMAGE_FILTERS_FILTER_H

class filter {
protected:
    int width;
    int height;
    int *pixels;
public:
    filter(int, int, int *);

    virtual ~filter();

    virtual int* process() = 0;
};

inline filter::filter(int width, int height, int *pixels)
        : width(width), height(height), pixels(pixels) {}

inline filter::~filter() {
    //delete[] pixels;
}

#endif //IMAGE_FILTERS_FILTER_H
