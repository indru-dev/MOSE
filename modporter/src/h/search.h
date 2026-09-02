#pragma once

#include <vector>
#include <windows.h>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class Modloader {
private:
    std::vector<HMODULE> loadedmods;

public:
    void loadmods(const fs::path&);
    void unloadmods();
};