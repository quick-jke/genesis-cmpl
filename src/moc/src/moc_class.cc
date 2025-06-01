#include "moc_class.hpp"

namespace quick{
namespace genesis{


MocClass::MocClass(){

}

void MocClass::write_to(std::ofstream& file){
    file << "start writing class\n"; 
    for(auto field : public_fields_){
        field.write_to(file);
    }
    for(auto field : private_fields_){
        field.write_to(file);
    }
    file << "end writing class\n";
}



}
}