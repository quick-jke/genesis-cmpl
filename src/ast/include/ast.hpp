#ifndef QUICK_GENESIS_AST_HPP
#define QUICK_GENESIS_AST_HPP
#include <filesystem>
#include <string>
#include "moc_class.hpp"

namespace quick{
namespace genesis{

class AST{
public:
    AST(const std::string& content);
    std::string content();

    void write_to(std::ofstream& file);

private:
    std::string content_;

    MocClass cls;
};


}
}


#endif