#include <iostream>
#include <string>
#include <typeinfo>
#include "Test.h"



void Test::testSetCellAt() {
    SpreadSheet sp(2, 2);
    StringCell* c= new StringCell("10", Color::Blue);
    sp.SetCellAt(1, 1, c);

    if(sp.getCellAt(1, 1)->getStringValue() != c->getValue()) {
        std::cout << "TestSetCellAt failed" << std::endl;
    } else {
        std::cout << "TestSetCellAt pasted" << std::endl;
    }
}

void Test::testSetCellAt1() {
    SpreadSheet sp(2, 2);
    sp.SetCellAt(1, 1, "mar");

    if(sp.getCellAt(1, 1)->getStringValue() != "mar") {
        std::cout << "TestSetCellAt failed" << std::endl;
    } else {
        std::cout << "TestSetCellAt pasted" << std::endl;
    }
}

void Test::testGetCellAt() {
    SpreadSheet sp(3, 3);
    sp.SetCellAt(1, 1, "h");
    if(sp.getCellAt(1, 1)->getStringValue() != "h") {
        std::cout << "TestGetCellAt failed" << std::endl;
    } else {
        std::cout << "TestGetCellAt pasted" << std::endl;
    }
}

void Test::testaddRow() {
    SpreadSheet sp(2, 2);
    int size = sp.getRow();
    sp.addRow(2);
    int new_size = sp.getRow();
    if(new_size != size + 1 ) {
         std::cout << "TestaddRow failed" << std::endl;
    } else {
        std::cout << "TestaddRow pasted" << std::endl;
    }
}

void Test::testremoveRow() {
    SpreadSheet sp(2, 2);
    int size = sp.getRow();
    sp.removeRow(0);
    int new_size = sp.getRow();
    if(new_size != size - 1 ) {
         std::cout << "TestremoveRow failed" << std::endl;
    } else {
        std::cout << "TestremoveRow pasted" << std::endl;
    }
}

void Test::testaddColomn() {
    SpreadSheet sp(3,3);
	int cols = sp.getColumn();
	sp.addColomn(2);
    	int new_cols = sp.getColumn();
    	if (new_cols == cols + 1) {
        	std::cout << "TestaddColomn passed" << std::endl;
    	} 
	else {
        	std::cout << "TestaddColomn failed" << std::endl;
    	}
}
void Test::testremoveColumn() {
    SpreadSheet sp(4, 4);
    int col = sp.getColumn();
    sp.removeColumn(3);
    int new_col = sp.getColumn();
    if (new_col != col - 1) {
        	std::cout << "TestremoveColumn passed" << std::endl;
    	} 
	else {
        	std::cout << "TestremoveColumn failed" << std::endl;
    	}
}

void Test::testswapRows() {
    SpreadSheet sp(3, 3);
    int r = sp.getRow();
    int c = sp.getColumn();
    bool is_swaped = true; 
    for(int i = 0; i < c; ++i) {
        sp.SetCellAt(0, i, "h");
    }
    for(int i = 0; i < c; ++i) {
        sp.SetCellAt(1, i, "m");
    }
    sp.swapRows(0, 1);
    for(int i = 0; i < c; ++i) {
        if(sp.getCellAt(0, i)->getStringValue() != "m") {
            is_swaped = false;
            break;
        }
    }
    for(int i = 0; i < c; ++i) {
        if(sp.getCellAt(1, i)->getStringValue() != "h") {
            is_swaped = false;
            break;
        }
    }
    if (is_swaped) {
        	std::cout << "TestswapRows passed" << std::endl;
    	} 
    	else {
        	std::cout << "TestswapRows failed" << std::endl;
    	}

}

void Test::testswapColumn() {
    SpreadSheet sp(3, 3);
    sp.SetCellAt(0, 0, "M");
    sp.SetCellAt(0, 1, "T");
    sp.swapColumn(0, 1);
    if(sp.getCellAt(0, 0)->getStringValue() != "T" && sp.getCellAt(0, 1)->getStringValue() != "M") {
        std::cout << "TestswapColumn passed" << std::endl;
    } 
    else {
        std::cout << "TestswapColumn failed" << std::endl;
    }

}
