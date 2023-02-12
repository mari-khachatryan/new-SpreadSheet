#include <string>
#include "SpreadSheet.h"

SpreadSheet::SpreadSheet(int new_row, int new_column) 
    :row{new_row}
    ,column{new_column}
{
    m_cell.resize(row);
    for(int i = 0; i < row; ++i) {
        m_cell[i].resize(column);        
    }
}

int SpreadSheet::getRow() {
    return row;
}

int SpreadSheet::getColumn() {
    return column;
}

void  SpreadSheet::SetCellAt(int r, int c, Cell* cl){
    if(r < 0 || r >= row || c < 0 || c >= column) {
        throw std::invalid_argument("Index is out of rang.");
    }
    m_cell[r][c] = cl;
}

void  SpreadSheet::SetCellAt(int r, int c, const std::string& cl) {
    if(r < 0 || r >= row || c < 0 || c >= column) {
        throw std::invalid_argument("Index is out of rang.");
    }
    StringCell* cell = new StringCell(cl, Color::Blue);
    cell->setValue(cl);
    m_cell[r][c] = cell;
}

Cell*  SpreadSheet::getCellAt(int r, int c) const {
    if(r < 0 || r >= row || c < 0 || c >= column) {
        throw std::invalid_argument("Index is out of rang.");
    }
    return m_cell[r][c];
}

void  SpreadSheet::addRow(int r) {
    if(r <= -1 || r >= row) {
        throw std::invalid_argument("Index is out of rang.");
    }
    StringCell* cell = new StringCell("-", Color::Blue);
    m_cell.insert(m_cell.begin() + r - 1, std::vector<Cell*>(column, cell));
    ++row;
}

void  SpreadSheet::removeRow(int r) {
    if(r < 0 || r >= row ) {
        throw std::invalid_argument("Index is out of rang.");
    }
    m_cell.erase(m_cell.begin() + r - 1);
    --row;
}

void   SpreadSheet::addColomn(int c) {
    if(c < 0 || c >= column) {
        throw std::invalid_argument("Index is out of rang.");
    }
    StringCell* cell = new StringCell("-", Color::Blue);
    for (int i = 0; i < row; i++) {
        m_cell[i].resize(column + 1);
        for (int j = c; j < column + 1; j++) {
            m_cell[i][j + 1] = m_cell[i][j];
        }
        m_cell[i][c] = cell;
    }
    ++column;
}

void   SpreadSheet::removeColumn(int c) {
    if(c < 0 || c >= column) {
        throw std::invalid_argument("Index is out of rang.");
    }
    for (int i = 0; i < row; ++i) {
        	for (int j = c; j < column - 1; ++j) {
            		m_cell[i][j] = m_cell[i][j+1];
        	}
        	m_cell[i].resize(column - 1);
    	}
        --column;
}

void  SpreadSheet::swapRows(int r1, int r2) {
    if(r1 < 0 || r2 >= row || r2 < 0 || r2 >= row) {
        throw std::invalid_argument("Index is out of rang.");
    }
    std::vector<Cell*> tmp = m_cell[r1];
    m_cell[r1] = m_cell[r2];
    m_cell[r2] = tmp;
}

void   SpreadSheet::swapColumn(int c1, int c2) {
    if(c1 < 0 || c1 >= column || c2 < 0 || c2 >= column) {
        throw std::invalid_argument("Index is out of rang.");
    }
    for (int i = 0; i < row; ++i) {
		Cell* tmp = m_cell[i][c1];
		m_cell[i][c1] = m_cell[i][c2];
		m_cell[i][c2] = tmp;
	}
}