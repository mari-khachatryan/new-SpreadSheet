#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <iostream>
#include <vector>
#include "Cell.h"

class SpreadSheet {
public:
    SpreadSheet() = default;
    SpreadSheet(int, int);
    virtual ~SpreadSheet() = default;

    int getRow();
    int getColumn();
    void SetCellAt(int, int, Cell*);
    void SetCellAt(int, int, const std::string& cl);
    Cell* getCellAt(int, int) const;
    void addRow(int);
    void removeRow(int);
    void addColomn(int);
    void removeColumn(int);
    void swapRows(int, int);
    void swapColumn(int, int);
private:
    std::vector<std::vector<Cell*>> m_cell;
    int row;
    int column;
};

#endif //SPREADSHEET_H