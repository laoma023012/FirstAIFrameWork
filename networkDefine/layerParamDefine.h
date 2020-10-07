//
// Created by mxc on 2020/9/27.
//
#include <iostream>
#ifndef FIRSTAIFRAMEWORK_LAYERPARAMDEFINE_H
#define FIRSTAIFRAMEWORK_LAYERPARAMDEFINE_H

class LayerParamDefine{
public:
    LayerParamDefine(){
        this->conv_size = 0;
        this->stride = 0;
    }
    int conv_size;
    int stride;
};

#endif //FIRSTAIFRAMEWORK_LAYERPARAMDEFINE_H
