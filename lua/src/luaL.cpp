#include "util.h"
#include <cstdlib>
#include <iostream>
#include <lua.h>
#include <luaL.h>

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

void luaL_enableClass(coreID ID) {
    switch(ID) {
        case coreID::MODLOADER:
            luaL_modl();
            break;
        default:
            break;
    }
}
