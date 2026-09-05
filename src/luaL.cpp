#include "util.h"
#include <cstdlib>
#include <iostream>
#include <lua.h>
#include <luaL.h>
#include <modl.h>

extern "C" {
    #include <lualib.h>
    #include <lauxlib.h>
}

void luaL_openstate(lua_State* L) {
    luaL_openlibs(L);

    if(luaL_dofile(L, "src/scripts/script.lua") != LUA_OK) {
        std::cerr << "[ERROR] (luaL) Unable to open script: " << lua_tostring(L, -1);
        lua_pop(L, 1);
        std::cin.get();
        core::terminate(EXIT_FAILURE);
    }
}

void luaL_enableClass(lua_State* L, coreID ID) {
    switch(ID) {
        case coreID::MODLOADER:
            luaL_modl(L);
            break;
        default:
            break;
    }
}

void luaL_registry(lua_State* L, classID ID) {
    switch(ID) {
        case classID::UTIL:
            utilC::registry(L);
            break;
        default:
            break;
    }
}
