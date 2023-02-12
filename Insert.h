#ifndef INSERT_H
#define INSERT_H


#include <iostream>
#include <string>
#include <fstream>
#include "SpreadSheet.h"

class Insert {
public:
    virtual ~Insert() = default;
    Insert(const std::string&, const SpreadSheet&);
    void setFileName(const std::string&);
    std::string getFileName() const;
    void write_to_faile();
private:
    std::string file_name;
    SpreadSheet sp;
};

#endif //INSERT_H