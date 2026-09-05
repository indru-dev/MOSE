#include <lau.h>
#include <luaL.h>
#include <modl.h>
#include <util.h>

Modloader loader = Modloader();

int main() {

    lua_State* L = luaL_newstate();
    luaL_openstate(L);

    luaL_enableClass(L, coreID::MODLOADER);
    luaL_registry(L, classID::UTIL);
    
    lua_close(L);
    return 0;
}