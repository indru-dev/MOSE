#pragma once
#include <modl.h>
#include <stdexcept>
#include <string>
#include <util.h>
#include <proc.h>

namespace core {
    extern Modloader loader;
    extern Procman procman;
}

template <typename T>
T& GetFromCore(coreID ID) {
    switch(ID) {
        case coreID::MODLOADER:
            return core::loader;
            break;
        case coreID::PROCMAN:
            return core::procman;
            break;
        default:
            throw std::runtime_error("Invalid Error Loading Object From Core.");
            break;
    }
}
