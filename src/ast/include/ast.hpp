#ifndef QUICK_GENESIS_AST_HPP
#define QUICK_GENESIS_AST_HPP
#include <filesystem>
#include <string>

namespace quick{
namespace genesis{

class AST{
public:
    AST(const std::string& content);
    std::string content();

private:
    std::string content_;
};


}
}


#endif