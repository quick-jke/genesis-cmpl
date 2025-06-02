#ifndef QUICK_GENESIS_AST_MOC_METHOD_HPP
#define QUICK_GENESIS_AST_MOC_METHOD_HPP

#include "IWritable.hpp"
#include <string>
namespace quick{
namespace genesis{

class MocMethod : public IWritable{
public:
    MocMethod(const std::string& method = "basic method");
    void write_to(std::ofstream& file) override;
private:
    std::string method_;
};


}}


#endif