#include "moc_class.hpp"

namespace quick{
namespace genesis{


MocClass::MocClass(){

}

void MocClass::push_private_field(MocField field){
    private_fields_.push_back(field);
}

std::string MocClass::class_name(){
    return class_name_;
}

std::vector<std::string> MocClass::imports(){
    return imports_;
}

void MocClass::set_class_name(const std::string& class_name){
    class_name_ = class_name;
}

void MocClass::set_imports(std::vector<std::string> imports){
    imports_ = imports;
}

void MocClass::write_to(std::ofstream& file){
    file << "//start writing class\n"; 
    file << "namespace " << namespace_ << std::endl;
    for(auto import : imports_){
        file << "#include \"" << import << "\"" << std::endl;
    }
    file << "class " << class_name_ << "{\n";
    file << "public:\n";
    for(auto field : public_fields_){
        field.write_to(file);
    }
    for(auto method : public_methods_){
        method.write_to(file);
    }
    file << "private:\n";

    for(auto field : private_fields_){
        field.write_to(file);
    }

    for(auto method: private_methods_){
        method.write_to(file);
    }

    file << "};\n";

    file << "} //namespace " << namespace_ << std::endl;
    file << "//end writing class\n";
}



}
}