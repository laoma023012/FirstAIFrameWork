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
            auto &paramNet = value["train"];
            this->learningRate = paramNet["learning rate"].asDouble();
            this->momentumParameter = paramNet[""].asDouble();
            this->batchSize = paramNet[""].asInt();
            this->useBatch = paramNet[""].asBool();
            this->evaluateInterval = paramNet[""].asInt();
            this->fineTune = paramNet[""].asBool();
            this->lrDecay = paramNet[""].asDouble();
            this->lrUpdate = paramNet[""].asBool();
            this->numEpochs = paramNet[""].asInt();
            this->preTrainModel = paramNet[""].asString();
            this->snapshot = paramNet[""].asBool();
            this->updateMethod = paramNet[""].asString();
        }
    }
}