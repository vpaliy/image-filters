#include <jni.h>
#include "include/jAutoArrayPtr.h"
#include "include/brightness.h"
#include "include/contrast.h"

static inline jintArray toJIntArray(JNIEnv *env, jint size, jint *arr) {
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
    return toJIntArray(env, width * height, _brightness.process());
}

extern "C"
JNIEXPORT jintArray JNICALL
Java_com_paliy_filters_NativeFilters_contrast(JNIEnv *env, jclass type, jint width, jint height,
                                              jintArray pixels_, jint factor) {
    jAutoArrayPtr<jintArray, jint> _ptr(env, pixels_);
    contrast _contrast = contrast(width, height, _ptr.get(), factor);
    return toJIntArray(env, width * height, _contrast.process());
}
