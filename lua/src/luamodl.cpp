#include <lauxlib.h>
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
