#include <jni.h>
#include "jAutoArrayPtr.h"
#include "brightness.h"
#include "contrast.h"
#include <android/log.h>
#define	TAG    "image-filters"
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

static jintArray toJIntArray(JNIEnv *env, jint size, jint *arr) {
    jintArray result = env->NewIntArray(size);
    env->SetIntArrayRegion(result, 0, size, arr);
    return result;
}

extern "C"
JNIEXPORT jintArray JNICALL
Java_com_paliy_filters_NativeFilters_brightness(JNIEnv *env, jclass type, jint width, jint height,
                                                jintArray pixels_, jint factor) {
    jAutoArrayPtr<jintArray, jint> _ptr(env, pixels_);
    brightness _brightness = brightness(width, height, _ptr.get(), factor);
    return  toJIntArray(env, width * height, _brightness.process());
}

extern "C"
JNIEXPORT jintArray JNICALL
Java_com_paliy_filters_NativeFilters_contrast(JNIEnv *env, jclass type, jint width, jint height,
                                              jintArray pixels_, jint factor) {
    jAutoArrayPtr<jintArray, jint> _ptr(env, pixels_);
    contrast _contrast = contrast(width, height, _ptr.get(), factor);
    return toJIntArray(env, width * height, _contrast.process());
}
