#include <iostream>
#include <lua.h>
#pragma once

namespace core {
    [[noreturn]] void terminate(int);

    namespace lua {
        int cout(lua_State*);
        int cerr(lua_State*);
        int sleep(lua_State*);
    }
}

namespace utilC {
    void registry(lua_State*);
}

enum class coreID {
    MODLOADER
};

enum class classID {
    UTIL
};