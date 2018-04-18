//
// Created by Vasyl Paliy on 4/17/18.
//

#ifndef IMAGE_FILTERS_JAUTOARRAYPTR_H
#define IMAGE_FILTERS_JAUTOARRAYPTR_H

#include <jni.h>

template<typename _Ta, typename _Tp>
class jAutoArrayPtr {
private:
    JNIEnv *env;
    _Ta &_array;
    _Tp *_pointer;

public:
    jAutoArrayPtr(JNIEnv *, _Ta);

    ~jAutoArrayPtr();

    jAutoArrayPtr(const jAutoArrayPtr<_Ta, _Tp> &) = delete;

    jAutoArrayPtr<_Ta, _Tp> &operator=(const jAutoArrayPtr<_Ta, _Tp> &) = delete;

    inline _Tp *get() const noexcept { return _pointer; }
};

template<typename _Ta, typename _Tp>
inline jAutoArrayPtr<_Ta, _Tp>::jAutoArrayPtr(JNIEnv *env, _Ta _array) noexcept
        : env(env), _array(_array), _pointer(nullptr) {}

template<>
inline jAutoArrayPtr<jintArray, jint>::jAutoArrayPtr(JNIEnv *env, jintArray _array) noexcept
        : env(env), _array(_array), _pointer(env->GetIntArrayElements(_array, NULL)) {}

template<>
inline jAutoArrayPtr<jintArray, jint>::~jAutoArrayPtr() {
    if (_pointer != nullptr) {
        env->ReleaseIntArrayElements(_array, _pointer, 0);
    }
}

#endif
