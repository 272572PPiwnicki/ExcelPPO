#include <iostream>
#include <limits>
#include "Cell.h"
#include "NumericCell.h"
#include "StringCell.h"
#include "Spreadsheet.h"

// Funkcja pomocnicza do czyszczenia bufora wejścia
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Funkcja pomocnicza do wyświetlania menu
void displayMenu() {
    std::cout << "========== MENU ==========" << std::endl;
    std::cout << "1. Dodaj wiersz" << std::endl;
    std::cout << "2. Dodaj kolumnę" << std::endl;
    std::cout << "3. Modyfikuj komórkę" << std::endl;
    std::cout << "4. Odczytaj wartość komórki" << std::endl;
    std::cout << "5. Oblicz sumę wybranych komórek" << std::endl;
    std::cout << "6. Oblicz średnią wybranych komórek" << std::endl;
    std::cout << "7. Zapisz arkusz do pliku" << std::endl;
    std::cout << "8. Wczytaj arkusz z pliku" << std::endl;
    std::cout << "9. Zakończ program" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Wybierz opcję: ";
}

// Funkcja do obsługi dodawania wiersza
void handleAddRow(Spreadsheet& spreadsheet) {
    spreadsheet.addRow();
    std::cout << "Dodano nowy wiersz." << std::endl;
}

// Funkcja do obsługi dodawania kolumny
void handleAddColumn(Spreadsheet& spreadsheet) {
    spreadsheet.addColumn();
    std::cout << "Dodano nową kolumnę." << std::endl;
}

// Funkcja do obsługi modyfikacji komórki
void handleModifyCell(Spreadsheet& spreadsheet) {
    int row, column;
    std::string value;

    std::cout << "Podaj numer wiersza: ";
    std::cin >> row;
    clearInputBuffer();

    std::cout << "Podaj numer kolumny: ";
    std::cin >> column;
    clearInputBuffer();

    std::cout << "Podaj nową wartość komórki: ";
    std::getline(std::cin, value);

    if (spreadsheet.modifyCell(row, column, value)) {
        std::cout << "Komórka została zmodyfikowana." << std::endl;
    }
    else {
        std::cout << "Nie można zmodyfikować komórki. Podano nieprawidłowy numer wiersza lub kolumny." << std::endl;
    }
}

// Funkcja do obsługi odczytu wartości komórki
void handleReadCellValue(Spreadsheet& spreadsheet) {
    int row, column;

    std::cout << "Podaj numer wiersza: ";
    std::cin >> row;
    clearInputBuffer();

    std::cout << "Podaj numer kolumny: ";
    std::cin >> column;
    clearInputBuffer();

    std::string value = spreadsheet.readCellValue(row, column);
    if (value != "") {
        std::cout << "Wartość komórki: " << value << std::endl;
    }
    else {
        std::cout << "Nieprawidłowy numer wiersza lub kolumny." << std::endl;
    }
}

// Funkcja do obsługi obliczania sumy wybranych komórek
void handleCalculateSum(Spreadsheet& spreadsheet) {
    int startRow, startColumn, endRow, endColumn;

    std::cout << "Podaj numer wiersza początkowego: ";
    std::cin >> startRow;
    clearInputBuffer();

    std::cout << "Podaj numer kolumny początkowej: ";
    std::cin >> startColumn;
    clearInputBuffer();

    std::cout << "Podaj numer wiersza końcowego: ";
    std::cin >> endRow;
    clearInputBuffer();

    std::cout << "Podaj numer kolumny końcowej: ";
    std::cin >> endColumn;
    clearInputBuffer();

    int sum = spreadsheet.calculateSum(startRow, startColumn, endRow, endColumn);
    if (sum != -1) {
        std::cout << "Suma wybranych komórek: " << sum << std::endl;
    }
    else {
        std::cout << "Nieprawidłowy zakres komórek." << std::endl;
    }
}

// Funkcja do obsługi obliczania średniej wybranych komórek
void handleCalculateAverage(Spreadsheet& spreadsheet) {
    int startRow, startColumn, endRow, endColumn;

    std::cout << "Podaj numer wiersza początkowego: ";
    std::cin >> startRow;
    clearInputBuffer();

    std::cout << "Podaj numer kolumny początkowej: ";
    std::cin >> startColumn;
    clearInputBuffer();

    std::cout << "Podaj numer wiersza końcowego: ";
    std::cin >> endRow;
    clearInputBuffer();

    std::cout << "Podaj numer kolumny końcowej: ";
    std::cin >> endColumn;
    clearInputBuffer();

    float average = spreadsheet.calculateAverage(startRow, startColumn, endRow, endColumn);
    if (average != -1) {
        std::cout << "Średnia wybranych komórek: " << average << std::endl;
    }
    else {
        std::cout << "Nieprawidłowy zakres komórek." << std::endl;
    }
}

// Funkcja do obsługi zapisu arkusza do pliku
void handleSaveToFile(Spreadsheet& spreadsheet) {
    std::string filename;

    std::cout << "Podaj nazwę pliku: ";
    std::getline(std::cin, filename);

    if (spreadsheet.saveToFile(filename)) {
        std::cout << "Arkusz został zapisany do pliku." << std::endl;
    }
    else {
        std::cout << "Nie można zapisać arkusza do pliku." << std::endl;
    }
}

// Funkcja do obsługi wczytania arkusza z pliku
void handleLoadFromFile(Spreadsheet& spreadsheet) {
    std::string filename;

    std::cout << "Podaj nazwę pliku: ";
    std::getline(std::cin, filename);

    if (spreadsheet.loadFromFile(filename)) {
        std::cout << "Arkusz został wczytany z pliku." << std::endl;
    }
    else {
        std::cout << "Nie można wczytać arkusza z pliku." << std::endl;
    }
}

int main() {
    Spreadsheet spreadsheet;

    int option;
    bool exit = false;

    while (!exit) {
        displayMenu();
        std::cin >> option;
        clearInputBuffer();

        switch (option) {
        case 1:
            handleAddRow(spreadsheet);
            break;
        case 2:
            handleAddColumn(spreadsheet);
            break;
        case 3:
            handleModifyCell(spreadsheet);
            break;
        case 4:
            handleReadCellValue(spreadsheet);
            break;
        case 5:
            handleCalculateSum(spreadsheet);
            break;
        case 6:
            handleCalculateAverage(spreadsheet);
            break;
        case 7:
            handleSaveToFile(spreadsheet);
            break;
        case 8:
            handleLoadFromFile(spreadsheet);
            break;
        case 9:
            exit = true;
            break;
        default:
            std::cout << "Nieprawidłowa opcja. Wybierz ponownie." << std::endl;
            break;
        }
    }

    return 0;
}
