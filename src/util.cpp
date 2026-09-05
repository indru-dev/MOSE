#include <iostream>
#include <lauxlib.h>
#include <lua.h>
#include <ostream>
#include <string>
#include <util.h>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

[[noreturn]] void core::terminate(int code) {

    cout << "[sys] Retrieved Termination Signal.";

    if(code == 0) {
        cout << "[sys] Termination Signal: EXIT_SUCCESS\n[SYS] Termination Code: 0";
    } else {
        cerr << "[sys] Termination Signal: EXIT_FAILURE\n[sys] Termination Code: " << code;
    }

    cout << "[sys] Entering Stage 1 => luaL"
    << endl << "[sys] Popping luaL stack..."
    << endl << "[sys] Closing luaL libraries..."
    << endl << "[sys] Waiting for Signal from Lua Script: scirpt.lua"
    << endl << "[sys] Terminating Lua state..."
    << endl << "[sys] Entering Stage 2 => _cpp_deinit"
    << endl << "[sys] Freeing Memory..."
    << endl << "[sys] Deconstructing..."
    << endl << "[sys] Proceeding with C++ Exit Procedure 1"
    << endl << "[sys] Proceeding with C++ Exit Procedure 2"
    << endl << "[sys] Proceeding with C++ Exit Procedure 3"
    << endl << "[sys] Proceeding with C3 Exit Procedure"
    << endl << "[sys] Entering Stage 3 => TERM"
    << endl << "[sys] Shutting Down Program..."
    << endl << "[sys] Entering C++ Exit Procedure 4"
    << endl << "[TERM]"
    << endl << "Bye!";

    exit(code);
}

namespace core::lua {

    int cout(lua_State* L) {
        std::string msg = luaL_checkstring(L, 1);
        
        std::cout << "[LUA] " << msg;
        return 0;
    }

    int cerr(lua_State* L) {
        std::string err = luaL_checkstring(L, 1);

        std::cerr << "[ERR] (lua) " << msg;
        return 0;
    }

    int sleep(lua_State* L) {
        double n = luaL_checknumber(L, 1);

        sleep_for(duration<double>(n));
        return 0;
    }
    
}

void utilC::registry(lua_State* L) {
    lua_register(L, "cout", core::lua::cout);
    lua_register(L, "cerr", core::lua::cerr);
    lua_register(L, "sleep", core::lua::sleep);
}