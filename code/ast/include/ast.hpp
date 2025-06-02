#ifndef QUICK_GENESIS_AST_HPP
#define QUICK_GENESIS_AST_HPP
#include <filesystem>
#include <string>
#include "moc_class.hpp"
#include <vector> 

namespace quick{
namespace genesis{

class AST{
public:
    AST(const std::vector<MocClass>& classes);
    std::string content();

    void write_to(std::ofstream& file);

private:
    std::string content_;
    std::vector<MocClass> classes_;
    MocClass cls;
};


}
}


#endif