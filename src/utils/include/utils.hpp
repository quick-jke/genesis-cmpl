#ifndef QUICK_GENESIS_UTILS_HPP
#define QUICK_GENESIS_UTILS_HPP

#include <filesystem>
#include <fstream>

namespace quick{
namespace genesis{
namespace utils{

std::string read_file(const std::filesystem::path& path);


}
}
}


#endif