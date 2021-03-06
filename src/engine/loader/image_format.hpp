#ifndef IMAGE_READER_H
  #define IMAGE_READER_H

#include "file_format.h"

namespace me {

  namespace format {

    struct image_format : file_format {

      ImageFileFormat format;

      image_format(ImageFileFormat format) : file_format(me::format::FileType::FTYPE_IMAGE)
      {
         this->format = format;
      }

      virtual int load_image(me::bytebuff &buffer, me::Image* image, uint64_t flags) = 0;
      virtual int write_image(me::bytebuff &buffer, me::Image* image, uint64_t flags) = 0;
      virtual bool recognized(me::fileattr &file) = 0;
      virtual std::vector<std::string> get_file_exts() = 0;
      virtual uint64_t supported_flags() = 0;

    };

  };

};

#endif
