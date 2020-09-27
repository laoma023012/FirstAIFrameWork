//
// Created by mxc on 2020/9/27.
//

#ifndef FIRSTAIFRAMEWORK_NETPARAMDEFINE_H
#define FIRSTAIFRAMEWORK_NETPARAMDEFINE_H

struct NetParamDefine {
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
};

#endif //FIRSTAIFRAMEWORK_NETPARAMDEFINE_H
