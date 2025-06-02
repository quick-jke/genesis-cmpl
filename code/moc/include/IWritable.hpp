#ifndef QUICK_GENESIS_AST_IWRITABLE_HPP
#define QUICK_GENESIS_AST_IWRITABLE_HPP

#include <fstream>

namespace quick{
namespace genesis{

class IWritable{
public:
    virtual ~IWritable() {}
    virtual void write_to(std::ofstream& file) = 0;

};
}}
#endif