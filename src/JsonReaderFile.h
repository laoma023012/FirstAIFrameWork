//
// Created by mxc on 2020/9/27.
//
#include <iostream>
#include <string>
#include "../networkDefine/layerParamDefine.h"
#include "../networkDefine/netParamDefine.h"
#include <unordered_map>
#ifndef FIRSTAIFRAMEWORK_JSONREADERFILE_H
#define FIRSTAIFRAMEWORK_JSONREADERFILE_H
class JsonReaderFile {
public:
    JsonReaderFile(std::string jsonName, LayerParamDefine &layerParamDefine, NetParamDefine &netParamDefine)
            : layerParamDefine(layerParamDefine), netParamDefine(netParamDefine) {
        readParam(jsonName);
    };
private:
    LayerParamDefine& layerParamDefine;
    NetParamDefine& netParamDefine;
    std::unordered_map<std::string, NetParamDefine> lparams;
    void readParam(std::string a);
};

#endif //FIRSTAIFRAMEWORK_JSONREADERFILE_H
