#include <minwindef.h>
#include <modl.h>
namespace fs = std::filesystem;

bool Modloader::checkIfMod(const fs::directory_entry& entry) {

    if(!entry.is_regular_file()) return false;
    if(entry.path().extension() != ".dll") return false;
    if(entry.is_symlink()) return false;

    return true;
}

std::vector<HMODULE> Modloader::GetAllMods() {
    return loaded;
}

void Modloader::loadMods(std::string path) {
    fs::path dir(path);

    for(const auto& file : fs::directory_iterator(dir)) {

        if(Modloader::checkIfMod(file) != 0) continue;

        HMODULE temp = LoadLibraryW(file.path().c_str());

        std::wstring native = file.path().wstring();
        HMODULE handle = GetModuleHandleW(native.c_str());

        if(handle) {
            std::wcout << L"Module: " << file.path().filename().wstring() << L" ) was loaded to the handle: " << handle << std::endl;
            loaded.push_back(temp);
        } else {
            std::wcerr << L"Module: " << file.path().filename().wstring() << L" ) could not be loaded." << std::endl;
        }
    
        DWORD error = GetLastError();

        if(error) {
            std::cerr << "[ERR] Error loading: " << file.path().filename() << ": " << error << std::endl;
        }
        
    }
}

void Modloader::unloadMods() {
    for(const auto& file : loaded) {
        FreeLibrary(file);
    }
}
 