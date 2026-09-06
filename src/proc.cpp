#include <cstdlib>
#include <util.h>
#include <modl.h>
#include <proc.h>

Procman::Procman() : loader(GetFromCore<Modloader>(coreID::MODLOADER)) {
    loaded = loader.GetAllMods();
}

void Procman::openMods() {
    for(HMODULE mod : loaded) {

        auto init = reinterpret_cast<DLLopen>(GetProcAddress(mod, "_init_"));

        if (init) init();

        if (!init) { 
            std::cout << "Mod does not have a _init_ function, unloading Mods and terminating program.";
            core::terminate(EXIT_FAILURE);
        }
    }
}

void Procman::closeMods() {
    for(HMODULE mod : loaded) {

        auto close = reinterpret_cast<DLLclose>(GetProcAddress(mod, "_close_"));

        if (close) close();

        if(!close) {
            std::cout << "Mod does not have a _close_ function, unloading Mods and terminating program.";
            core::terminate(EXIT_FAILURE);
        }
    }
}