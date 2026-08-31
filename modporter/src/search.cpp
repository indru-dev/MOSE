#include <filesystem>
#include "search.h"

namespace fs = std::filesystem;

bool uemptymods() {
    bool found = false;
    
    if(fs::exists("../../mods") && fs::is_directory("../../mods")) {
        for (const auto& entry : fs::directory_iterator("../../mods")) {
            if(entry.is_directory()) {
                found = true;
                break;
            }
        }
    }

    if(found) {
        return true;
    } else {
        return false;
    }

}