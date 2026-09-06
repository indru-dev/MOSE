#pragma once
#include <vector>
#include <windows.h>
#include <modl.h>
#include <fromcore.h>
#include <util.h>

using DLLopen = void(*)();
using DLLclose = void(*)();

class Procman {
public:
    Modloader& loader;
    std::vector<HMODULE> loaded;

    Procman();

    void openMods();
    void closeMods();
    
};

void luaL_proc(lua_State*);

namespace lua {
    int luaL_openMods(lua_State*);
    int luaL_closeMods(lua_State*);
}

