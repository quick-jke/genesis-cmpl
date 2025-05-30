#include "parser.hpp"



namespace quick{
namespace genesis{

const AST Parser::parse(const std::string& content){
    return AST(content);
}

}
}