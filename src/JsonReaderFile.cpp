//
// Created by mxc on 2020/9/27.
//

#include "JsonReaderFile.h"
#include <fstream>
#include <json/json.h>
#include <iostream>
#include "assert.h"
void JsonReaderFile::readParam(std::string json_txt) {
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
            this->netParamDefine.learningRate = paramNet["learning rate"].asDouble();
            this->netParamDefine.momentumParameter = paramNet["lr decay"].asDouble();
            this->netParamDefine.batchSize = paramNet["batch size"].asInt();
            this->netParamDefine.useBatch = paramNet["use batch"].asBool();
            this->netParamDefine.evaluateInterval = paramNet["evaluate interval"].asInt();
            this->netParamDefine.fineTune = paramNet["fine tune"].asBool();
            this->netParamDefine.lrDecay = paramNet["lr decay"].asDouble();
            this->netParamDefine.lrUpdate = paramNet["lr update"].asBool();
            this->netParamDefine.numEpochs = paramNet["num epochs"].asInt();
            this->netParamDefine.preTrainModel = paramNet["pre train model"].asString();
            this->netParamDefine.snapshot = paramNet["snapshot"].asBool();
            this->netParamDefine.updateMethod = paramNet["update Method"].asString();
        }
    }
}