#include "moc_field.hpp"


namespace quick{
namespace genesis{

MocField::MocField(const std::string& field) : field_(field){

}
void MocField::write_to(std::ofstream& file){
    file << "\t" << field_ << std::endl; 
}

}
}