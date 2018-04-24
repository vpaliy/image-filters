#include <jni.h>
#include "auto_array_ptr.h"
#include "brightness.h"
#include "contrast.h"
#include "filters-lib.h"

using namespace filters;

JNIEXPORT jintArray JNICALL
Java_com_paliy_filters_NativeFilters_brightness(JNIEnv *env, jclass type, jint width_, jint height_,
                                                jintArray pixels_, jint factor) {
  filters::pixels_wrapper *_wrapper = new filters::pixels_wrapper(env, pixels_);
  brightness _brightness = brightness(width(width_), height(height_),
                                      std::shared_ptr<pixels_wrapper>(_wrapper),
                                      brightness::options(factor));
  return _brightness.process();
}

JNIEXPORT jintArray JNICALL
Java_com_paliy_filters_NativeFilters_contrast(JNIEnv *env, jclass type, jint width_, jint height_,
                                              jintArray pixels_, jint factor) {
  pixels_wrapper *_wrapper = new pixels_wrapper(env, pixels_);
  contrast _contrast = contrast(width(width_), height(height_),
                                std::shared_ptr<pixels_wrapper>(_wrapper),
                                contrast::options(factor));
  return _contrast.process();
}
