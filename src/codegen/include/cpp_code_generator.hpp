#ifndef QUICK_GENESIS_CPP_CODE_GENERATOR_HPP
#define QUICK_GENESIS_CPP_CODE_GENERATOR_HPP
#include "ast.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
namespace quick{
namespace genesis{

class CppCodeGenerator{
public:
    CppCodeGenerator(AST& ast);
    void generate(const std::string& out, const std::string& name);
private:
    AST ast_;
};


}
}


#endif