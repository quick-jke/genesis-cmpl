#ifndef QUICK_GENESIS_AST_MOC_FILED_HPP
#define QUICK_GENESIS_AST_MOC_FILED_HPP

#include "IWritable.hpp"
#include <string>

namespace quick{
namespace genesis{

class MocField : public IWritable{
public:
    MocField(const std::string& field = "basic field");
    void write_to(std::ofstream& file) override;
private:
    std::string field_;
};

}}

#endif