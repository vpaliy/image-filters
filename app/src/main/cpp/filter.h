
#ifndef IMAGE_FILTERS_FILTER_H
#define IMAGE_FILTERS_FILTER_H

#include"auto_array_ptr.h"
#include<memory>

namespace filters {
  struct width {
    const int value;
    explicit width(int value) : value(value) {}
  };

  struct height {
    const int value;
    explicit height(int value) : value(value) {}
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
    size _size;
    std::shared_ptr<pixels_wrapper> _pointer;
  public:
    filter(width const &, height const &, std::shared_ptr<pixels_wrapper>);

    virtual jintArray process() = 0;
  };

  inline filter::filter(width const &_width, height const &_height,
                        std::shared_ptr<pixels_wrapper> _pointer)
          : _size(_width, _height), _pointer(_pointer) {}
}

#endif
