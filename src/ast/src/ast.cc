#include "ast.hpp"


namespace quick{
namespace genesis{
    

AST::AST(const std::string& content) : content_(content){}

std::string AST::content(){
    return content_;
}

}
}