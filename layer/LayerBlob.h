//
// Created by mxc on 2020/10/8.
//
#include <iostream>
#include <armadillo>
#ifndef FIRSTAIFRAMEWORK_LAYERBLOB_H
#define FIRSTAIFRAMEWORK_LAYERBLOB_H

enum FillType{
    /***
     * TONES = 1 cube 所有元素填充为1
     * TZEROS = 2 cube 所有元素填充为0
     * TRANDU = 3 cube 所有元素设置为[0,1]区间内均匀分布的随机值
     * TRANDN = 4 cube 所有元素使用 标准高斯分布设置元素
     * TDEFAULT = 5
     */
    TONES = 1,
    TZEROS = 2,
    TRANDU = 3,
    TRANDN = 4,
    TDEFAULT = 5
};

class Blob{
public:
    Blob():N_(0), C_(0), H_(0), W_(0){};
    Blob(const int n, const int c, const int h, const int w, int type = TDEFAULT);
private:
    void _init(const int n, const int c, const int h, const int w, int type);
    int N_; int C_; int H_; int W_;
    std::vector<arma::cube> blobData;
};

#endif //FIRSTAIFRAMEWORK_LAYERBLOB_H
