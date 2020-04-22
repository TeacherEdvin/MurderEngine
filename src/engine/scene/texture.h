#ifndef TEXTURE_H
  #define TEXTURE_H

#include <atomic>
#include <cstdint>
#include "metadata.h"

namespace me {

  enum ImageFormat : unsigned char {
    ME_IMG_FORMAT_RGB =                    0x03,
    ME_IMG_FORMAT_RGBA =                   0x14,
    ME_IMG_FORMAT_BINARY =                 0x21,
    ME_IMG_FORMAT_GRAY =                   0x31,
    ME_IMG_FORMAT_GRAY_ALPHA =             0x42
  };

  enum WColorType : unsigned char {
    ME_WCOLOR_MAP = 0,
    ME_WCOLOR_COLOR = 1,
    ME_WCOLOR_FLOAT = 2
  };

  struct Bitmap {
    uint32_t width, height;
    unsigned char depth;
    unsigned char* map;
  };

  struct ImageInfo {
    uint32_t glBindId;
    std::string source;
    std::string identifier;
    me::metadata* metadata;
    ImageFormat format;
  };

  struct Image {

    Bitmap* bitmap;
    ImageInfo info;

    Image(Bitmap* bitmap, ImageInfo info)
    {
      this->bitmap = bitmap;
      this->info = info;
    }

    Image(std::string source)
    {
      info.source = source;
    }

    Image() { }

    ~Image()
    {
    }

  };

  struct ImageSequence {

    std::string source;
    std::string identifier;

    uint32_t frameCount;
    uint32_t fps;
    ImageFormat imageFormat;
    std::vector<Bitmap*> frames;

    ImageSequence(std::string source, std::string identifier)
    {
      this->source = source;
      this->identifier = identifier;
    }

    ImageSequence(std::string source, std::string identifier, uint32_t frameCount, uint32_t fps, ImageFormat format)
    {
      this->source = source;
      this->identifier = identifier;
      this->frameCount = frameCount;
      this->fps = fps;
      this->imageFormat = imageFormat;
    }

    ImageSequence() { }

    ~ImageSequence() { }

    bool hasNext();
    Bitmap* nextFrame();

  };

  struct wcolor { // stands for wide-color. yes i know very stupid

    unsigned char type;
    void* data;

    wcolor(me::Image* image)
    {
      type = WColorType::ME_WCOLOR_MAP;
      this->data = image;
    }

    wcolor(me::vec4* color)
    {
      type = WColorType::ME_WCOLOR_COLOR;
      this->data = color;
    }

    wcolor(float* f)
    {
      type = WColorType::ME_WCOLOR_FLOAT;
      this->data = f;
    }

    wcolor()
    {
    }

    ~wcolor()
    {
    }

  };

  /* helpers */
  inline uint32_t min_bit_rate(ImageFormat format)
  {
    if (format == ME_IMG_FORMAT_RGB)
      return 24;
    else if (format == ME_IMG_FORMAT_RGBA)
      return 32;
    else if (format == ME_IMG_FORMAT_GRAY)
      return 8;
    else if (format == ME_IMG_FORMAT_BINARY)
      return 1;
    else if (format == ME_IMG_FORMAT_GRAY_ALPHA)
      return 16;
    return 0;
  }

};

#endif
