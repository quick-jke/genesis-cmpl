#include "moc_method.hpp"


namespace quick{
namespace genesis{

MocMethod::MocMethod(const std::string& method) : method_(method){

}
void MocMethod::write_to(std::ofstream& file){
    file << "\t" << method_ << std::endl; 
}

}
}