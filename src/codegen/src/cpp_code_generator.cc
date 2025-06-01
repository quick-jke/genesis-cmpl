#include "cpp_code_generator.hpp"

namespace quick{
namespace genesis{

CppCodeGenerator::CppCodeGenerator(AST& ast) : ast_(ast){
    
}

void CppCodeGenerator::generate(const std::string& out, const std::string& name){
    std::filesystem::path header_file_path = out + "/" + name + ".hpp";
    std::filesystem::path cpp_file_path = out + "/" + name + ".cc";


    std::filesystem::path dir_path = header_file_path.parent_path();

    std::error_code ec;
    std::filesystem::create_directories(dir_path, ec);

    if (ec) {
        std::cerr << "Error while creating directories: " << ec.message() << std::endl;
        return;
    }

    std::ofstream hfile(header_file_path);
    if (!hfile) {
        std::cerr << "Can not create file: " << header_file_path << std::endl;
        return;
    }
    std::ofstream ccfile(cpp_file_path);
    if (!ccfile) {
        std::cerr << "Can not create file: " << cpp_file_path << std::endl;
        return;
    }


    ast_.write_to(hfile);
    ast_.write_to(ccfile);

    // std::cout << "File created success: " << file_path << std::endl;
}

}
}