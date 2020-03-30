#ifndef SHADER_H
  #define SHADER_H

#define ME_SHADER_TYPE_VERTEX            15
#define ME_SHADER_TYPE_FRAGMENT          76

namespace me {

  struct shader : mem_utils {
    std::string identifier;
    unsigned int programId;
    const char* source;
    ~shader()
    {
      delete[] source; // ?
    }

    long mem_use() override
    {
      return identifier.size() +
      sizeof(unsigned int) +
      sizeof(source);
    }

  };

};

#endif
