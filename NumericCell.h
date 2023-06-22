#ifndef NUMERICCELL_H
#define NUMERICCELL_H

#include "Cell.h"

class NumericCell : public Cell {
public:
    NumericCell();
    NumericCell(int value);

    std::string getValue() const override;
    void setValue(const std::string& value) override;
    std::string getType() const override;

    // Dodatkowe metody dla operacji numerycznych

private:
    int m_value;
};

#endif  // NUMERICCELL_H
