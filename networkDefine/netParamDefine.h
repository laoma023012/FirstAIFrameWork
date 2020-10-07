//
// Created by mxc on 2020/9/27.
//

#ifndef FIRSTAIFRAMEWORK_NETPARAMDEFINE_H
#define FIRSTAIFRAMEWORK_NETPARAMDEFINE_H

struct NetParamDefine {
    NetParamDefine(){
        this->learningRate = 0.0;
        this->lrDecay = 0.0;
        this->updateMethod = "";
        this->momentumParameter = 0.0;
        this->numEpochs = 0;
        this->useBatch = false;
        this->batchSize = 0;
        this->evaluateInterval = 0;
        this->lrUpdate = false;
        this->snapshot = false;
        this->snapshotInterval = 0;
        this->fineTune = false;
        this->preTrainModel = "";
    }
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
