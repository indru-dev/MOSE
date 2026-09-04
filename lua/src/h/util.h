#include <iostream>
#pragma once

namespace core {
    [[noreturn]] void terminate(int);
}

enum class coreID {
    MODLOADER
};