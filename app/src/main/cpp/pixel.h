
#ifndef IMAGE_FILTERS_PIXEL_H
#define IMAGE_FILTERS_PIXEL_H

class pixel final {
private:
  int color;
public:
  explicit pixel(int color);

  int R();

  int G();

  int B();

  int alpha();

  static int fromRGB(int R, int G, int B);

  static int fromRGBA(int alpha, int R, int G, int B);
};

#endif
