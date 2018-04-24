
#ifndef IMAGE_FILTERS_FILTERS_LIB_H
#define IMAGE_FILTERS_FILTERS_LIB_H

#include <jni.h>


#ifdef __cplusplus
extern "C" {
JNIEXPORT jintArray JNICALL
Java_com_paliy_filters_NativeFilters_brightness(JNIEnv *env, jclass type, jint width_, jint height_,
                                                jintArray pixels_, jint factor);
JNIEXPORT jintArray JNICALL
Java_com_paliy_filters_NativeFilters_contrast(JNIEnv *env, jclass type, jint width_, jint height_,
                                              jintArray pixels_, jint factor);
#ifdef __cplusplus
}
#endif
#endif
