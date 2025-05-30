#include "utils.hpp"


namespace quick{
namespace genesis{
namespace utils{

std::string read_file(const std::filesystem::path& path){
    
    if (!std::filesystem::exists(path)) {
        throw std::runtime_error("File does not exist: " + path.string());
    }

    std::ifstream file(path, std::ios::in | std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + path.string());
    }

    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::string content(size, '\0');

    file.read(content.data(), static_cast<std::streamsize>(size));

    if (!file) {
        throw std::runtime_error("Failed to read file: " + path.string());
    }

    return content;
}


}
}
}