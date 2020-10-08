#include <iostream>
#include <armadillo>
#include "json/json.h"
#include <string>
#include "layer/LayerBlob.h"
#include <fstream>
#include "src/JsonReaderFile.h"
#include "networkDefine/netParamDefine.h"
#include "networkDefine/layerParamDefine.h"
using namespace std;
//using namespace Json;
using namespace arma;
void testJSON(){

    arma::mat A = arma::randu<arma::mat>(4,5);
    arma::mat B = arma::randu<arma::mat>(4,5);

    std::cout << A*B.t() << std::endl;
    //std::cout << "hello World" << std::endl;

    Json::Value root ;
    Json::Reader reader;
    const char* s = R"({"uploadid": "UP000000","code": 100,"msg": "","files": ""})";
    if(!reader.parse(s, root, false)){
        // "parse fail";
    }
    else{
        std::cout << root["uploadid"].asString();//print "UP000000"
    }
}
void testParameter(){
    const char* json_txt = "../networkDefine/layerDefine.json";
    LayerParamDefine layerParamDefine;
    NetParamDefine netParamDefine;
    JsonReaderFile jsonReaderFile(json_txt, netParamDefine);
    cout << netParamDefine.learningRate << endl;
    cout << netParamDefine.lrDecay << endl;
    cout << netParamDefine.momentumParameter << endl;
    cout << netParamDefine.numEpochs << endl;
    cout << netParamDefine.useBatch << endl;
    cout << netParamDefine.batchSize << endl;
    cout << netParamDefine.evaluateInterval << endl;
    cout << netParamDefine.lrUpdate << endl;
    cout << netParamDefine.snapshot << endl;
    cout << netParamDefine.snapshotInterval << endl;
    cout << netParamDefine.preTrainModel << endl;
    cout << netParamDefine.fineTune << endl;
    cout << netParamDefine.updateMethod << endl;
    cout << "--------------------------" << endl;

    cout << "print current layer name" << endl;
    for(auto& currentName : jsonReaderFile.layerName ){
        //cout << currentName << endl;
    }

    cout << "print current layer type" << endl;
    for(auto& currentType : jsonReaderFile.layerType){
        //cout << currentType << endl;
    }

    for(auto& currentLayerParam : jsonReaderFile.lparams){
        cout << "current Layer Name is " << currentLayerParam.first << endl;
        auto& currentLayerParamSecond = currentLayerParam.second;
        cout << currentLayerParamSecond.conv_kernels << endl;
        cout << currentLayerParamSecond.conv_width << endl;
        cout << currentLayerParamSecond.conv_height << endl;
        cout << currentLayerParamSecond.conv_pad << endl;
        cout << currentLayerParamSecond.conv_stride << endl;

        cout << currentLayerParamSecond.pool_width << endl;
        cout << currentLayerParamSecond.pool_height << endl;
        cout << currentLayerParamSecond.pool_stride << endl;

        cout << currentLayerParamSecond.fc_kernels << endl;
    }
}

void testBlob(){
    Blob blob(2,3,5,3, TONES);
    //blob.print();

    Blob blob2(2,3,5,3, TZEROS);
    //blob2.print();

    Blob blob3(2,3,5,3, TRANDN);
    //blob3.print();

    Blob blob4(2,3,5,3, TRANDU);
    //blob4.print();

    Blob blob5(2,3,5,3);
    blob5.print();
}

void testImage(){
    Blob* images(new Blob(10, 1, 32, 32));
}

int main(int arg, char** argv) {
    //testParameter();
    //testBlob();
    return 0;
}