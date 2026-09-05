#pragma once
#include <util.h>
#include <lau.h>
#include <fromcore.h>

void luaL_openstate(lua_State*);

void luaL_enableClass(lua_State*, coreID);

void luaL_registry(lua_State* L, classID);