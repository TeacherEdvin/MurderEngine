#ifndef LUA_LANG_H
  #define LUA_LANG_H

#include "../../../kernel/kernel.h"

namespace me {

  namespace lang {

    struct lua {

      int load_lua_script(const std::string &filepath);

    };

  };

};

#endif
