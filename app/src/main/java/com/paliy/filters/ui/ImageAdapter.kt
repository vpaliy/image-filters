package com.paliy.filters.ui

import android.support.v7.widget.RecyclerView
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import com.paliy.filters.R
import kotlinx.android.synthetic.main.adapter_thumbnail_item.view.*

class ImageAdapter (val callback:(Thumbnail)->Unit) : RecyclerView.Adapter<ImageAdapter.ViewHolder>() {
  var data = mutableListOf<Thumbnail>()
    set(value) {
      if (field != value) {
        field = value
        notifyDataSetChanged()
      }
    }

  inner class ViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {

    fun bind(): Unit = with(itemView) {
      itemView.setOnClickListener {
        callback(data[adapterPosition])
      }
      val item = data[adapterPosition]
      title.text = item.filter
      image.setImageBitmap(item.imageFilter.process())
    }
  }

  override fun getItemCount() = data.size

  override fun onBindViewHolder(holder: ViewHolder?, position: Int) {
    holder?.bind()
  }

  override fun onCreateViewHolder(parent: ViewGroup, viewType: Int)
      = ViewHolder(LayoutInflater.from(parent.context)
      ?.inflate(R.layout.adapter_thumbnail_item, parent, false)!!)
}