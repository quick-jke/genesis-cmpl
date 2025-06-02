#include <iostream>
#include "genesis.hpp"
#include <string>
#include <filesystem>
#include <vector>
#include "parser.hpp"
#include "cpp_code_generator.hpp"
#include "utils.hpp"


class Compiler {
public:
    Compiler(const config& config) : config_(config) {}

    void run() {
        // std::cout << config_.out_path << std::endl;
        if (std::filesystem::exists(config_.out_path)) {
            std::filesystem::remove_all(config_.out_path); 
        }
        std::filesystem::create_directories(config_.out_path);

        auto def_files = find_def_files(config_.def_path);
        if (def_files.empty()) {
            std::cerr << "No .def files found in input directory.\n";
            return;
        }
        int i = 0;
        for (const auto& file_path : def_files) {
            // std::cout << file_path << std::endl;
            try {
                process_file(file_path, file_path.stem());
                ++i;
            } catch (const std::exception& e) {
                std::cerr << "Error processing " << file_path << ": " << e.what() << "\n";
            }
        }
    }

private:
    config config_;

    void process_file(const std::filesystem::path& file_path, const std::string& name) {
        std::string content = quick::genesis::utils::read_file(file_path);

        quick::genesis::AST ast = quick::genesis::Parser::parse(content);

        quick::genesis::CppCodeGenerator generator(ast);
        generator.generate(config_.out_path, name);
    }

    std::vector<std::filesystem::path> find_def_files(const std::filesystem::path& dir) {
        std::vector<std::filesystem::path> def_files;
        if (!std::filesystem::exists(dir) || !std::filesystem::is_directory(dir)) {
            throw std::runtime_error("Input directory does not exist: " + dir.string());
        }
        for (const auto& entry : std::filesystem::directory_iterator(dir)) {
            if (entry.path().extension() == ".def") {
                def_files.push_back(entry.path());
            }
        }
        return def_files;
    }
};

int main(int argc, char* argv[]){
    try{
        auto config = get_cmd_path(argc, argv);
        
        Compiler compiler(config);
        compiler.run();

        return 0;

    }catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}

