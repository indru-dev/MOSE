#include "h/search.h"

void Modloader::loadmods(const fs::path& moddir) {
    if(!fs::exists(moddir)) {
        std::cout << "[err] Mods folder not found at: " << moddir.string();
        std::cout << "[fix.d] Creating Mods folder...";
        fs::create_directories(moddir);

        if(!fs::exists(moddir)) {
            std::cout << "[CRITICAL] Mods folder cannot be artificially created." << std::endl;
            core::terminate(EXIT_FAILURE);
        }
    }
}

