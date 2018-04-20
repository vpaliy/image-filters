package com.paliy.filters.ui

import android.annotation.SuppressLint
import android.graphics.Bitmap
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import com.bumptech.glide.Glide
import com.bumptech.glide.request.target.ImageViewTarget
import com.paliy.filters.BrightnessFilter
import com.paliy.filters.ContrastFilter
import com.paliy.filters.R
import io.reactivex.Single
import io.reactivex.android.schedulers.AndroidSchedulers
import io.reactivex.schedulers.Schedulers
import kotlinx.android.synthetic.main.activity_main.*

@SuppressLint("RxLeakedSubscription")
class MainActivity : AppCompatActivity() {

  private val adapter by lazy {
    ImageAdapter(this::load)
  }

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_main)
    prepareThumbnails()
    filters.adapter = adapter
  }

  private fun load(thumbnail: Thumbnail) {
    progressBar.show()
    Glide.with(this)
        .load(R.drawable.sunset)
        .asBitmap()
        .into(object : ImageViewTarget<Bitmap>(currentImage) {
          override fun setResource(resource: Bitmap?) {
            Single.fromCallable({
              thumbnail.imageFilter
                  .setBitmap(resource).process()
            }).subscribeOn(Schedulers.computation())
                .observeOn(AndroidSchedulers.mainThread())
                .doFinally({ progressBar.hide() })
                .subscribe({
                  currentImage.setImageBitmap(it)
                }, Throwable::printStackTrace)
          }
        })
  }

  private fun prepareThumbnails() {
    Single.fromCallable {
      Glide.with(this)
          .load(R.drawable.sunset)
          .asBitmap()
          .centerCrop()
          .into(150, 150).get()
    }.flatMap { Single.just(provideThumbnails(it)) }
        .subscribeOn(Schedulers.io())
        .observeOn(AndroidSchedulers.mainThread())
        .subscribe({
          adapter.data = it
          load(it.first())
        }, Throwable::printStackTrace)
  }

  private fun provideThumbnails(bitmap: Bitmap): MutableList<Thumbnail> {
    val list = mutableListOf<Thumbnail>()
    (1..255).forEach {
      val brightness = Thumbnail(R.string.brightness, BrightnessFilter(bitmap, it))
      val contrast = Thumbnail(R.string.contrast, ContrastFilter(bitmap, it))
      list += contrast
      list += brightness
    }
    return list
  }

  private fun View.show() {
    visibility = View.VISIBLE
  }

  private fun View.hide() {
    visibility = View.GONE
  }
}
