#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "Cell.h"
#include "Spreadsheet.h"


int main() {
    Spreadsheet spreadsheet;

    // Dodaj przykładowe dane do arkusza
    spreadsheet.addRow();
    spreadsheet.addColumn();
    spreadsheet.setCellContent(0, 0, "Hello");
    spreadsheet.setCellContent(0, 1, "World");
    spreadsheet.setCellContent(1, 0, "42");
    spreadsheet.setCellContent(1, 1, "3.14");
    spreadsheet.setCellType(1, 0, "number");
    spreadsheet.setCellType(1, 1, "number");

    // Odczytaj zawartość komórki
    std::cout << "Cell (0, 0): " << spreadsheet.getCellContent(0, 0) << std::endl;

    // Oblicz sumę liczb w arkuszu
    double sum = spreadsheet.calculateSum();
    std::cout << "Sum: " << sum << std::endl;

    // Oblicz średnią liczb w arkuszu
    double average = spreadsheet.calculateAverage();
    std::cout << "Average: " << average << std::endl;

    // Zapisz arkusz do pliku
    spreadsheet.saveToFile("spreadsheet.csv");

    // Wczytaj arkusz z pliku
    Spreadsheet loadedSpreadsheet;
    loadedSpreadsheet.loadFromFile("spreadsheet.csv");

    // Odczytaj zawartość wczytanego arkusza
    std::cout << "Cell (0, 0) from loaded spreadsheet: " << loadedSpreadsheet.getCellContent(0, 0) << std::endl;

    return 0;
}
