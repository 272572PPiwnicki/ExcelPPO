#ifndef STRINGCELL_H
#define STRINGCELL_H

#include "Cell.h"

class StringCell : public Cell {
public:
    StringCell();
    StringCell(const std::string& value);

    std::string getValue() const override;
    void setValue(const std::string& value) override;
    std::string getType() const override;

private:
    std::string m_value;
};

#endif  // STRINGCELL_H
