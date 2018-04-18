package com.paliy.filters.ui

import android.graphics.Bitmap
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.support.v7.widget.LinearLayoutManager
import com.bumptech.glide.Glide
import com.bumptech.glide.request.target.ImageViewTarget
import com.paliy.filters.BrightnessFilter
import com.paliy.filters.R
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

  private val adapter by lazy {
    ImageAdapter(this::load)
  }

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_main)
    filters.layoutManager = LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false)
    filters.adapter = adapter
    prepareThumbnails()
  }

  private fun load(thumbnail: Thumbnail) {
    Glide.with(this)
        .load(R.drawable.sunset)
        .asBitmap()
        .into(object:ImageViewTarget<Bitmap>(currentImage) {
          override fun setResource(resource: Bitmap?) {
            currentImage.setImageBitmap(thumbnail.imageFilter
                .setBitmap(resource).process())
          }
        })
  }

  private fun prepareThumbnails() {
    val item = Glide.with(this)
        .load(R.drawable.sunset)
        .asBitmap()
        .centerCrop()
        .into(150,150).get()
    val brightness = Thumbnail(R.string.brightness, BrightnessFilter(item, 10))
    val contrast = Thumbnail(R.string.brightness, BrightnessFilter(item, 10))
    adapter.data = mutableListOf(brightness, contrast)
  }
}
