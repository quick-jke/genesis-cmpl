#include "ast.hpp"


namespace quick{
namespace genesis{
    

AST::AST(const std::vector<MocClass>& classes) : classes_(classes){
    
}

std::string AST::content(){
    return "/*\n" + content_ + "\n*/";
}

void AST::write_to(std::ofstream& file){
    file << "/*\n";
    for(auto cls : classes_){
        cls.write_to(file);
    }
    file << "\n*/";
}

}
}