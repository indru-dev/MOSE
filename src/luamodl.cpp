#include <lauxlib.h>
#include <lua.h>
#include <modl.h>
#include <fromcore.h>

Modloader loader = GetFromCore<Modloader>(coreID::MODLOADER);

int lua::luaL_loadMods(lua_State* L) {
    std::string path = luaL_checkstring(L, 1);
    loader.loadMods(path);

    return 0;
} 

int lua::luaL_unloadMods(lua_State* L) {
    loader.unloadMods();
    return 0;
}

void luaL_modl(lua_State* L) {
    lua_newtable(L);

    lua_pushcfunction(L, lua::luaL_loadMods);
    lua_setfield(L, -2, "loadMods");
    
    lua_pushcfunction(L, lua::luaL_unloadMods);    
    lua_setfield(L, -2, "unloadMods");
    
    lua_setglobal(L, "Modloader");
}