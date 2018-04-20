//
// Created by Vasyl Paliy on 4/17/18.
//

#ifndef IMAGE_FILTERS_PIXEL_H
#define IMAGE_FILTERS_PIXEL_H


class pixel final {
private:
    int color;
public:
    explicit pixel(int);
    int R();
    int G();
    int B();
    int alpha();
    static int fromRGB(int, int, int);
    static int fromRGBA(int, int, int, int);
};


#endif
