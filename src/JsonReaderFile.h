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
struct jsonReaderFile{
    LayerParamDefine& layerParamDefine;
    std::unordered_map<std::string, NetParamDefine> lparams;
    void readParam(std::string);
};

#endif //FIRSTAIFRAMEWORK_JSONREADERFILE_H
