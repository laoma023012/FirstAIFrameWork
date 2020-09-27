//
// Created by mxc on 2020/9/27.
//

#include "JsonReaderFile.h"
#include <fstream>
#include <json/json.h>
#include <iostream>
#include "assert.h"
jsonReaderFile& jsonReaderFile::readParam(std::string json_txt) {
    std::ifstream ifs;
    ifs.open(json_txt);
    assert(ifs.is_open());
    Json::Value value;
    Json::Reader reader;
    if(!reader.parse(ifs, value)){
        std::cout << "error Read" << std::endl;
    } else {
        if (!value["train"].isNull()){

        }
    }
}