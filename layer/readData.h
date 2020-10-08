//
// Created by mxc on 2020/10/8.
//
#include <iostream>
#include <memory>
#include "LayerBlob.h"
#ifndef FIRSTAIFRAMEWORK_READDATA_H
#define FIRSTAIFRAMEWORK_READDATA_H

class ReadData {
private:
    int ReverseInt(int i);
public:
    void readMinistData(std::string, std::shared_ptr<Blob> &images);
    void readMinistLabel(std::string, std::shared_ptr<Blob> &labels);
};

#endif //FIRSTAIFRAMEWORK_READDATA_H
