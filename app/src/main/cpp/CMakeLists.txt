cmake_minimum_required(VERSION 3.4.1)
add_library(filters-lib  SHARED
             brightness.cpp
             contrast.cpp
             pixel.cpp
             gaussian_blur.cpp
             gamma_correction.cpp
             filters-lib.cpp)

find_library(log-lib
              log )

target_link_libraries(filters-lib
                      android
                      log)