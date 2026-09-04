#pragma once
#include <modl.h>
#include <util.h>

extern Modloader loader;

template <typename T>
T GetFromCore(coreID ID) {
    if(ID == coreID::MODLOADER) return loader;
}
