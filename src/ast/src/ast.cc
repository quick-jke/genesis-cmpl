#include "ast.hpp"


namespace quick{
namespace genesis{
    

AST::AST(const std::string& content) : content_(content){
    cls = MocClass();
}

std::string AST::content(){
    return "/*\n" + content_ + "\n*/";
}

void AST::write_to(std::ofstream& file){
    file << "/*\n";
    cls.write_to(file);
    file << "\n*/";
}

}
}