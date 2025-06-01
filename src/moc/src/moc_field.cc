#include "moc_field.hpp"


namespace quick{
namespace genesis{

MocField::MocField(){

}
void MocField::write_to(std::ofstream& file){
    file << "writing field\n"; 
}

}
}