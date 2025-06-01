#ifndef QUICK_GENESIS_AST_MOC_METHOD_HPP
#define QUICK_GENESIS_AST_MOC_METHOD_HPP

#include "IWritable.hpp"

namespace quick{
namespace genesis{

class MocMethod : public IWritable{
public:
    MocMethod();
    void write_to(std::ofstream& file) override;
private:
    
};


}}


#endif