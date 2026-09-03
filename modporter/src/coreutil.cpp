#include "h/coreutil.h"
using namespace std;

[[noreturn]] void core::terminate(int code) {

    if (code == 0) {
        std::cout << "CODE: 0" << endl << "EXIT_SUCCESS\n";
    } else {
        std::cout << "CODE: " << code << endl << "EXIT_ERROR" << endl;
    }

    std::cout << endl << "[SYS] Performing C++ exit procedures...\n"
            << "[$] CXX\n"
            << "[SYS] Deconstructing Classes...\n"
            << "[SYS] Freeing Memory...\n"
            << "[SYS] Closing program...\n"
            << "[TERMINATE] TERMINATION IMMINENT\n"
            << "[$(std::exit)]";

}