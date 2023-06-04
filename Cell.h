#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

// Klasa reprezentuj�ca pojedyncz� kom�rk� w arkuszu
class Cell {
private:
    std::string content;
    std::string type;

public:
    Cell() {
        content = "";
        type = "text";
    }

    void setContent(const std::string& newContent) {
        content = newContent;
    }

    std::string getContent() const {
        return content;
    }

    void setType(const std::string& newType) {
        type = newType;
    }

    std::string getType() const {
        return type;
    }
};