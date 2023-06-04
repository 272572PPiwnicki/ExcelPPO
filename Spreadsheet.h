#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

// Klasa reprezentuj¹ca arkusz kalkulacyjny
class Spreadsheet {
private:
    std::vector<std::vector<Cell>> grid;

public:
    void addRow() {
        std::vector<Cell> row;
        grid.push_back(row);
    }

    void addColumn() {
        for (std::vector<Cell>& row : grid) {
            Cell cell;
            row.push_back(cell);
        }
    }

    void setCellContent(int row, int col, const std::string& content) {
        if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size()) {
            grid[row][col].setContent(content);
        }
    }

    std::string getCellContent(int row, int col) const {
        if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size()) {
            return grid[row][col].getContent();
        }
        return "";
    }

    void setCellType(int row, int col, const std::string& type) {
        if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size()) {
            grid[row][col].setType(type);
        }
    }

    std::string getCellType(int row, int col) const {
        if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size()) {
            return grid[row][col].getType();
        }
        return "";
    }

    double calculateSum() const {
        double sum = 0.0;
        int count = 0;

        for (const std::vector<Cell>& row : grid) {
            for (const Cell& cell : row) {
                if (cell.getType() == "number") {
                    try {
                        sum += std::stod(cell.getContent());
                        count++;
                    }
                    catch (std::exception& e) {
                        // Ignoruj nieprawid³owe wartoœci liczbowe
                    }
                }
            }
        }

        return sum;
    }

    double calculateAverage() const {
        double sum = calculateSum();
        if (sum != 0.0) {
            int count = 0;

            for (const std::vector<Cell>& row : grid) {
                for (const Cell& cell : row) {
                    if (cell.getType() == "number") {
                        count++;
                    }
                }
            }

            return sum / count;
        }

        return 0.0;
    }

    bool saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        for (const std::vector<Cell>& row : grid) {
            for (const Cell& cell : row) {
                file << cell.getContent() << ",";
            }
            file << std::endl;
        }

        file.close();
        return true;
    }

    bool loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        grid.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::vector<Cell> row;
            std::stringstream ss(line);
            std::string cellContent;

            while (std::getline(ss, cellContent, ',')) {
                Cell cell;
                cell.setContent(cellContent);
                row.push_back(cell);
            }

            grid.push_back(row);
        }

        file.close();
        return true;
    }
};