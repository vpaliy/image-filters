
#ifndef IMAGE_FILTERS_JAUTOARRAYPTR_H
#define IMAGE_FILTERS_JAUTOARRAYPTR_H

#include <jni.h>
#include <memory>

namespace filters {
  template<typename _Ta, typename _Tp>
  class auto_array_ptr {
  private:
    JNIEnv *env;
    _Ta _array;
    _Tp *_pointer;

  public:
    auto_array_ptr(JNIEnv *, _Ta) noexcept;

    ~auto_array_ptr();

    _Ta getArray() const;

    _Tp *get() const;

#if __cplusplus < 201103L
    private:
      auto_array_ptr(const auto_array_ptr<_Ta, _Tp>&);

      auto_array_ptr<_Ta, _Tp> &
      operator=(auto_array_ptr<_Ta, _Tp>);
#else
  public:
    auto_array_ptr(const auto_array_ptr<_Ta, _Tp> &) = delete;

    auto_array_ptr(auto_array_ptr<_Ta, _Tp> &&) = delete;

    auto_array_ptr<_Ta, _Tp> &
    operator=(auto_array_ptr<_Ta, _Tp>) = delete;

#endif
  };

  template<typename _Ta, typename _Tp>
  inline auto_array_ptr<_Ta, _Tp>::auto_array_ptr(JNIEnv *env, _Ta _array) noexcept
          : env(env), _array(_array), _pointer(nullptr) {}

  template<typename _Ta, typename _Tp>
  inline _Tp *auto_array_ptr<_Ta, _Tp>::get() const {
    return _pointer;
  }

  template<typename _Ta, typename _Tp>
  inline _Ta auto_array_ptr<_Ta, _Tp>::getArray() const {
    return _array;
  }

  template<>
  inline auto_array_ptr<jintArray, jint>::auto_array_ptr(JNIEnv *env, jintArray _array) noexcept
          : env(env), _array(_array), _pointer(env->GetIntArrayElements(_array, nullptr)) {}

  template<>
  inline auto_array_ptr<jintArray, jint>::~auto_array_ptr() {
    if (_pointer != nullptr) {
      env->ReleaseIntArrayElements(_array, _pointer, 0);
    }
  }

  typedef auto_array_ptr<jintArray, jint> pixels_wrapper;
}

#endif
