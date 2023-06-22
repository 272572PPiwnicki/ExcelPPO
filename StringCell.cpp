#include "StringCell.h"

StringCell::StringCell() {}

StringCell::StringCell(const std::string& value) : m_value(value) {}

std::string StringCell::getValue() const {
    return m_value;
}

void StringCell::setValue(const std::string& value) {
    m_value = value;
}

std::string StringCell::getType() const {
    return "String";
}
