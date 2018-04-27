#include <jni.h>
#include "include/auto_array_ptr.h"
#include "include/brightness.h"
#include "include/contrast.h"
#include "include/filters-lib.h"
#include "include/gaussian_blur.h"
#include "include/gamma_correction.h"

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

JNIEXPORT jintArray JNICALL
Java_com_paliy_filters_NativeFilters_gammaCorrection(JNIEnv *env, jclass type, jint width_,
                                                     jint height_, jintArray pixels_, jint gamma) {
  pixels_wrapper *_wrapper = new pixels_wrapper(env, pixels_);
  gamma_correction _filter = gamma_correction(width(width_), height(height_),
                                std::shared_ptr<pixels_wrapper>(_wrapper),
                                gamma_correction::options(gamma));
  return _filter.process();
}

JNIEXPORT jintArray JNICALL
Java_com_paliy_filters_NativeFilters_gaussianBlur(JNIEnv *env, jclass type, jint width_, jint height_,
                                                  jintArray pixels_, jint gamma) {
  pixels_wrapper *_wrapper = new pixels_wrapper(env, pixels_);
  gaussian_blur _blur = gaussian_blur(width(width_), height(height_),
                                std::shared_ptr<pixels_wrapper>(_wrapper),
                                gaussian_blur::options(gamma));
  return _blur.process();
}