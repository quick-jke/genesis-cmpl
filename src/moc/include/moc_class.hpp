#ifndef QUICK_GENESIS_AST_MOC_CLASS_HPP
#define QUICK_GENESIS_AST_MOC_CLASS_HPP

#include "IWritable.hpp"
#include "moc_field.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace quick{
namespace genesis{

class MocClass : public IWritable{
public:
    MocClass();
    void write_to(std::ofstream& file) override;
private:
    std::vector<MocField> private_fields_;
    std::vector<MocField> public_fields_;
};
}}
#endif