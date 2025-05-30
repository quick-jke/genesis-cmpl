#include "cpp_code_generator.hpp"

namespace quick{
namespace genesis{

CppCodeGenerator::CppCodeGenerator(AST& ast) : ast_(ast){
    
}

void CppCodeGenerator::generate(const std::string& out, const std::string& name){
    std::filesystem::path file_path = out + "/" + name + ".hpp";

    std::filesystem::path dir_path = file_path.parent_path();

    std::error_code ec;
    std::filesystem::create_directories(dir_path, ec);

    if (ec) {
        std::cerr << "Error while creating directories: " << ec.message() << std::endl;
        return;
    }

    std::ofstream file(file_path);
    if (!file) {
        std::cerr << "Can not create file: " << file_path << std::endl;
        return;
    }


    file << ast_.content();

    // std::cout << "File created success: " << file_path << std::endl;
}

}
}