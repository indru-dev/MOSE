#include <lau.h>
#include <luaL.h>
#include <modl.h>
#include <util.h>


namespace core {

    Modloader loader;
}

int main() {

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    luaL_enableClass(L, coreID::MODLOADER);
    luaL_registry(L, classID::UTIL);

    luaL_openstate(L);
    
    lua_close(L);
    return 0;
}