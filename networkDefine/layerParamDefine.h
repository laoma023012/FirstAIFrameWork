//
// Created by mxc on 2020/9/27.
//
#include <iostream>
#ifndef FIRSTAIFRAMEWORK_LAYERPARAMDEFINE_H
#define FIRSTAIFRAMEWORK_LAYERPARAMDEFINE_H

class LayerParamDefine{
public:
    LayerParamDefine(){
        this->conv_stride = 0;
        this->conv_pad = 0;
        this->conv_width = 0;
        this->conv_height = 0;
        this->conv_kernels = 0;
        this->pool_stride = 0;
        this->pool_width = 0;
        this->pool_height = 0;
        this->fc_kernels = 0;
    }
    /***
     * 卷积层的参数
     */
    int conv_stride;
    int conv_pad;
    int conv_width;
    int conv_height;
    int conv_kernels;

    /***
     * 池化层的参数
     */
    int pool_stride;
    int pool_width;
    int pool_height;

    /***
     * 全连接层的神经元个数
     */
    int fc_kernels;
};

#endif //FIRSTAIFRAMEWORK_LAYERPARAMDEFINE_H
