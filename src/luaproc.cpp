#include <lua.h>
#include <proc.h>
#include <fromcore.h>

Procman& procman = GetFromCore<Procman>(coreID::PROCMAN);

int lua::luaL_openMods(lua_State* L) {
    procman.openMods();
    return 0;
}

int lua::luaL_closeMods(lua_State* L) {
    procman.closeMods();
    return 0;
}

void luaL_proc(lua_State* L) {
    lua_newtable(L);

    lua_pushcfunction(L, lua::luaL_openMods);
    lua_setfield(L, -2, "openMods");

    lua_pushcfunction(L, lua::luaL_closeMods);
    lua_setfield(L, -2, "closeMods");

    lua_setglobal(L, "Procman");
}