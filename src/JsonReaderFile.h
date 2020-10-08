//
// Created by mxc on 2020/9/27.
//
#include <iostream>
#include <string>
#include "../networkDefine/layerParamDefine.h"
#include "../networkDefine/netParamDefine.h"
#include <unordered_map>
#include <vector>
#include <string>
#ifndef FIRSTAIFRAMEWORK_JSONREADERFILE_H
#define FIRSTAIFRAMEWORK_JSONREADERFILE_H
class JsonReaderFile {
public:
    JsonReaderFile(std::string jsonName,
                   //LayerParamDefine &layerParamDefine,
                   NetParamDefine &netParamDefine):  netParamDefine(netParamDefine){

        readParam(jsonName);
    };
    std::unordered_map<std::string, LayerParamDefine> lparams;
    std::vector<std::string> layerName;
    std::vector<std::string> layerType;
private:
    //LayerParamDefine& layerParamDefine;
    NetParamDefine& netParamDefine;
    void readParam(std::string jsonPath);
    //constexpr unsigned int str2int( const char* str, int h = 0) ;
};

#endif //FIRSTAIFRAMEWORK_JSONREADERFILE_H
