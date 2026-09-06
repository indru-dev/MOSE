#pragma once
#include <modl.h>
#include <stdexcept>
#include <string>
#include <util.h>

namespace core {
    extern Modloader loader;
}

template <typename T>
T& GetFromCore(coreID ID) {
    if(ID == coreID::MODLOADER) return core::loader;
    
    throw std::runtime_error("Invalid Error Loading Object From Core.");
}
