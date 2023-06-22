#ifndef CELL_H
#define CELL_H

#include <string>

class Cell {
public:
    virtual ~Cell() {}

    virtual std::string getValue() const = 0;
    virtual void setValue(const std::string& value) = 0;
    virtual std::string getType() const = 0;
};

#endif  // CELL_H
