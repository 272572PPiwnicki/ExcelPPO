#include "Spreadsheet.h"
#include "NumericCell.h"
#include "StringCell.h"
#include <fstream>
#include <iostream>

Spreadsheet::Spreadsheet() {}

void Spreadsheet::addRow() {
    // Dodaj nowy wiersz do m_cells
    std::vector<Cell*> row;
    for (size_t i = 0; i < m_cells[0].size(); ++i) {
        row.push_back(new StringCell());
    }
    m_cells.push_back(row);
}

void Spreadsheet::addColumn() {
    // Dodaj now¹ kolumnê do m_cells
    for (size_t i = 0; i < m_cells.size(); ++i) {
        m_cells[i].push_back(new StringCell());
    }
}

void Spreadsheet::modifyCell(int row, int column, const std::string& value) {
    // Modyfikuj komórkê o okreœlonym wierszu i kolumnie
    if (row >= 0 && row < m_cells.size() && column >= 0 && column < m_cells[0].size()) {
        Cell* cell = m_cells[row][column];
        cell->setValue(value);
    }
}

std::string Spreadsheet::getCellValue(int row, int column) const {
    // Zwróæ wartoœæ komórki o okreœlonym wierszu i kolumnie
    if (row >= 0 && row < m_cells.size() && column >= 0 && column < m_cells[0].size()) {
        Cell* cell = m_cells[row][column];
        return cell->getValue();
    }
    return "";
}

std::string Spreadsheet::getCellType(int row, int column) const {
    // Zwróæ typ komórki o okreœlonym wierszu i kolumnie
    if (row >= 0 && row < m_cells.size() && column >= 0 && column < m_cells[0].size()) {
        Cell* cell = m_cells[row][column];
        return cell->getType();
    }
    return "";
}

std::string Spreadsheet::calculateSum(int startRow, int endRow, int startColumn, int endColumn) const {
    // Oblicz sumê komórek w okreœlonym zakresie
    if (startRow >= 0 && startRow <= endRow && endRow < m_cells.size() &&
        startColumn >= 0 && startColumn <= endColumn && endColumn < m_cells[0].size()) {
        int sum = 0;
        for (int i = startRow; i <= endRow; ++i) {
            for (int j = startColumn; j <= endColumn; ++j) {
                Cell* cell = m_cells[i][j];
                if (cell->getType() == "Numeric") {
                    NumericCell* numericCell = dynamic_cast<NumericCell*>(cell);
                    sum += std::stoi(numericCell->getValue());
                }
            }
        }
        return std::to_string(sum);
    }
    return "";
}

std::string Spreadsheet::calculateAverage(int startRow, int endRow, int startColumn, int endColumn) const {
    // Oblicz œredni¹ komórek w okreœlonym zakresie
    if (startRow >= 0 && startRow <= endRow && endRow < m_cells.size() &&
        startColumn >= 0 && startColumn <= endColumn && endColumn < m_cells[0].size()) {
        int sum = 0;
        int count = 0;
        for (int i = startRow; i <= endRow; ++i) {
            for (int j = startColumn; j <= endColumn; ++j) {
                Cell* cell = m_cells[i][j];
                if (cell->getType() == "Numeric") {
                    NumericCell* numericCell = dynamic_cast<NumericCell*>(cell);
                    sum += std::stoi(numericCell->getValue());
                    ++count;
                }
            }
        }
        if (count > 0) {
            double average = static_cast<double>(sum) / count;
            return std::to_string(average);
        }
    }
    return "";
}

void Spreadsheet::saveToFile(const std::string& filename) const {
    // Zapisz arkusz do pliku w formacie CSV
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& row : m_cells) {
            for (const auto& cell : row) {
                file << cell->getValue() << ",";
            }
            file << "\n";
        }
        file.close();
        std::cout << "Arkusz zosta³ zapisany do pliku: " << filename << std::endl;
    }
    else {
        std::cerr << "B³¹d podczas zapisywania do pliku." << std::endl;
    }
}

void Spreadsheet::loadFromFile(const std::string& filename) {
    // Wczytaj arkusz z pliku w formacie CSV
    std::ifstream file(filename);
    if (file.is_open()) {
        m_cells.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::vector<Cell*> row;
            std::string value;
            std::istringstream iss(line);
            while (std::getline(iss, value, ',')) {
                if (std::isdigit(value[0])) {
                    row.push_back(new NumericCell(value));
                }
                else {
                    row.push_back(new StringCell(value));
                }
            }
            m_cells.push_back(row);
        }
        file.close();
        std::cout << "Arkusz zosta³ wczytany z pliku: " << filename << std::endl;
    }
    else {
        std::cerr << "B³¹d podczas wczytywania z pliku." << std::endl;
    }
}
