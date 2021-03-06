#ifndef MESH_LOADER_H
  #define MESH_LOADER_H

#include "file_format.h"

namespace me {

  namespace format {

    enum MeshFormat {
      MESH_FORMAT_VNTC,
      MESH_FORMAT_VERTEX
    };

    struct scene_format : file_format {

      SceneFileFormat format;

      scene_format(SceneFileFormat format) : file_format(me::format::FileType::FTYPE_SCENE)
      {
        this->format = format;
      }

      virtual int load_scene(me::bytebuff &buffer, ScenePacket* scene, uint64_t flags) = 0;
      virtual bool recognized(me::fileattr &file) = 0;
      virtual std::vector<std::string> get_file_exts() = 0;
      virtual uint64_t supported_flags() = 0;

    };

    void formatMesh(me::Mesh* mesh, MeshFormat format);

  };


};

#endif
