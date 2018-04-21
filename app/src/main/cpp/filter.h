
#ifndef IMAGE_FILTERS_FILTER_H
#define IMAGE_FILTERS_FILTER_H

#include"auto_array_ptr.h"
#include<memory>

struct width {
  int value;
  explicit width(int value)
          : value(value) {}
};

struct height {
  int value;
  explicit height(int value)
          : value(value) {}
};

struct size {
  const width _width;
  const height _height;

  inline size(const width &_width, const height &_height)
          : _width(_width), _height(_height) {}

  inline operator int() {
    return _width.value * _height.value;
  }
};

class filter {
protected:
  std::shared_ptr<pixels_wrapper> _pointer;
  size _size;
public:
  filter(width, height, std::shared_ptr<pixels_wrapper>);

  virtual jintArray process() = 0;
};

inline filter::filter(width _width, height _height,
                      std::shared_ptr<pixels_wrapper> _pointer)
        : _size(_width, _height), _pointer(_pointer) {}

#endif
