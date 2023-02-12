#include <iostream>
#include <fstream>
#include "Test.h"
#include "Cell.h"
#include "Insert.h"

int main() {
    try{
        Test t;
        t.testSetCellAt();
        t.testGetCellAt();
        t.testaddRow();
        t.testremoveRow();
        t.testaddColomn();
        t.testremoveColumn();
        t.testswapRows();
        t.testswapColumn();

        const int r = 2;
        const int c = 2;
        SpreadSheet sp(r, c);
        IntCell* c1 = new IntCell(15, Color::Blue);
        DoubleCell* c2 = new DoubleCell(5.5, Color::Blue);
        StringCell* c3 = new StringCell("Hello", Color::Blue);
        Date date("11.06.2005");
        DateCell* c4 = new DateCell(date, Color::Blue);
        sp.SetCellAt(0, 0, c1);
        sp.SetCellAt(0, 1, c2);
        sp.SetCellAt(1, 0, c3);
        sp.SetCellAt(1, 1, c4);
        Insert insert("shellData.txt", sp);
        insert.write_to_faile();
        return 0;

    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
    }
    
}