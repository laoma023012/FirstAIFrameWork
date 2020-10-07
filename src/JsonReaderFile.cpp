//
// Created by mxc on 2020/9/27.
//

#include "JsonReaderFile.h"
#include <fstream>
#include <json/json.h>
#include <iostream>
#include "assert.h"
constexpr unsigned int JsonReaderFile::str2int(const char* str, int h ) {
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

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
            auto &netParamNet = value["train"];
            this->netParamDefine.learningRate = netParamNet["learning rate"].asDouble();
            this->netParamDefine.momentumParameter = netParamNet["momentum parameter"].asDouble();
            this->netParamDefine.batchSize = netParamNet["batch size"].asInt();
            this->netParamDefine.useBatch = netParamNet["use batch"].asBool();
            this->netParamDefine.evaluateInterval = netParamNet["evaluate interval"].asInt();
            this->netParamDefine.fineTune = netParamNet["fine tune"].asBool();
            this->netParamDefine.lrDecay = netParamNet["lr decay"].asDouble();
            this->netParamDefine.lrUpdate = netParamNet["lr update"].asBool();
            this->netParamDefine.numEpochs = netParamNet["num epochs"].asInt();
            this->netParamDefine.preTrainModel = netParamNet["pre train model"].asString();
            this->netParamDefine.snapshot = netParamNet["snapshot"].asBool();
            this->netParamDefine.updateMethod = netParamNet["update method"].asString();
            this->netParamDefine.snapshotInterval = netParamNet["snapshot interval"].asInt();
        }
        if(!value["net"].isNull()){
            auto &layerParamNet = value["net"];
            for(auto & thisLayer : layerParamNet){
                this->layerName.push_back(thisLayer["name"].asString());
                this->layerType.push_back(thisLayer["type"].asString());
                if(thisLayer["type"].asString() == "Conv"){
                    this->layerParamDefine.conv_kernels = thisLayer["kernel num"].asInt();
                    this->layerParamDefine.conv_width = thisLayer["kernel width"].asInt();
                    this->layerParamDefine.conv_height = thisLayer["kernel height"].asInt();
                    this->layerParamDefine.conv_pad = thisLayer["pad"].asInt();
                    this->layerParamDefine.conv_stride = thisLayer["stride"].asInt();
                }
                if(thisLayer["type"].asString() == "Pool"){
                    
                }
                if(thisLayer["type"].asString() == "Fc"){}
            }
        }
    }
}