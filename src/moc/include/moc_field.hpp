#ifndef QUICK_GENESIS_AST_MOC_FILED_HPP
#define QUICK_GENESIS_AST_MOC_FILED_HPP

#include "IWritable.hpp"

namespace quick{
namespace genesis{

class MocField : public IWritable{
public:
    MocField();
    void write_to(std::ofstream& file) override;
private:

};

}}

#endif