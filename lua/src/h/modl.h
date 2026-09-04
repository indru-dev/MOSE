#pragma once
#include <libloaderapi.h>
#include <vector>
#include <filesystem>
#include <string>
#include <iostream>
#include <windows.h>
#include <lau.h>

namespace fs = std::filesystem;

class Modloader {
public:
    std::vector<HMODULE> loaded;

    static bool checkIfMod(const fs::directory_entry&);
    
    void loadMods(std::string);

    void unloadMods();
    
};

namespace lua {

    int luaL_loadMods(lua_State*);
    int luaL_unloadMods(lua_State*);
    
}