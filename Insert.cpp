#include "Insert.h"

Insert::Insert(const std::string& new_f, const SpreadSheet& new_sp) 
    :file_name{new_f}
    ,sp{new_sp} 
{}

void Insert::setFileName(const std::string& new_f) {
    file_name = new_f;
}

std::string Insert::getFileName() const {
    return file_name;
}

void Insert::write_to_faile() {
    std::ofstream myfile;
    myfile.open(getFileName());
    if(!myfile.is_open()) {
        std::cout << "File is not open" << std::endl;
    } else {
        for(int i = 0; i < sp.getRow(); i++) {
            for(int j = 0; j < sp.getColumn(); j++) {
                    myfile << i << ":" << j << sp.getCellAt(i, j)->getStringValue();
            }
    }
    myfile.close();
    }
}