#include "NumericCell.h"

NumericCell::NumericCell() : m_value(0) {}

NumericCell::NumericCell(int value) : m_value(value) {}

std::string NumericCell::getValue() const {
    return std::to_string(m_value);
}

void NumericCell::setValue(const std::string& value) {
    // Mo¿esz dodaæ obs³ugê walidacji wartoœci (czy jest liczb¹ ca³kowit¹)
    m_value = std::stoi(value);
}

std::string NumericCell::getType() const {
    return "Numeric";
}

// Dodatkowe metody dla operacji numerycznych
