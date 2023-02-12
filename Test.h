#ifndef TEST_H
#define TEST_H


#include <iostream>
#include <string>
#include "SpreadSheet.h"

class Test {
public:
    Test() = default;
    virtual ~Test() = default;

    void testSetCellAt();
    void testSetCellAt1();
    void testGetCellAt();
    void testaddRow();
    void testremoveRow();
    void testaddColomn();
    void testremoveColumn();
    void testswapRows();
    void testswapColumn();
};

#endif //TEST_H