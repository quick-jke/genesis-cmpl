#ifndef QUICK_GENESIS_PARSER_HPP
#define QUICK_GENESIS_PARSER_HPP
#include "ast.hpp"
#include <iostream>
#include <string>
namespace quick{
namespace genesis{

class Parser{
public:
    static const AST parse(const std::string& content);
};

}
}

#endif