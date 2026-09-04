#include <exception>
#include <ostream>
#include <util.h>
#include <cstdlib>
using namespace std;

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