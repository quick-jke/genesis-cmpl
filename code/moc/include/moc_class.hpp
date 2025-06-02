#ifndef QUICK_GENESIS_AST_MOC_CLASS_HPP
#define QUICK_GENESIS_AST_MOC_CLASS_HPP

#include "IWritable.hpp"
#include "moc_field.hpp"
#include "moc_method.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace quick{
namespace genesis{

class MocClass : public IWritable{
public:
    MocClass();
    void write_to(std::ofstream& file) override;

    void push_private_field(MocField field);
    std::string class_name();
    void set_class_name(const std::string& class_name);
    std::vector<std::string> imports();
    void set_imports(std::vector<std::string> imports);
private:
    std::string class_name_;
    std::string namespace_;
    std::vector<std::string> imports_;
    std::vector<MocField> private_fields_;
    std::vector<MocField> public_fields_;
    std::vector<MocMethod> public_methods_;
    std::vector<MocMethod> private_methods_;

};
}}
#endif