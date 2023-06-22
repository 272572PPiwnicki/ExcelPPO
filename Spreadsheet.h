#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include "Cell.h"
#include <vector>

class Spreadsheet {
public:
    Spreadsheet();

    void addRow();
    void addColumn();
    void modifyCell(int row, int column, const std::string& value);
    std::string getCellValue(int row, int column) const;
    std::string getCellType(int row, int column) const;
    std::string calculateSum(int startRow, int endRow, int startColumn, int endColumn) const;
    std::string calculateAverage(int startRow, int endRow, int startColumn, int endColumn) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<std::vector<Cell*>> m_cells;

    // Dodatkowe prywatne metody wspomagające
};

#endif  // SPREADSHEET_H
