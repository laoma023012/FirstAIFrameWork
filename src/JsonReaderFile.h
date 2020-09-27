//
// Created by mxc on 2020/9/27.
//
#include <iostream>
#include <string>
#ifndef FIRSTAIFRAMEWORK_JSONREADERFILE_H
#define FIRSTAIFRAMEWORK_JSONREADERFILE_H
struct jsonReaderFile{
    double learningRate;
    double lrDecay;
    std::string updateMethod;
    double momentumParameter;
    int numEpochs;
    bool useBatch;
    int batchSize;
    int evaluateInterval;
    bool lrUpdate;
    bool snapshot;
    int snapshotInterval;
    bool fineTune;
    std::string preTrainModel;
    jsonReaderFile& readParam(std::string);
};

#endif //FIRSTAIFRAMEWORK_JSONREADERFILE_H
