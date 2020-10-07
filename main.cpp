#include <iostream>
#include <armadillo>
#include "json/json.h"
#include <string>
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

int main() {
    const char* json_txt = "../networkDefine/layerDefine.json";
    LayerParamDefine layerParamDefine;
    NetParamDefine netParamDefine;
    JsonReaderFile jsonReaderFile(json_txt, layerParamDefine, netParamDefine);
    cout << netParamDefine.learningRate << endl;
    /*
    Json::Value root;
    Json::Reader reader;
    ifstream ifs;
    ifs.open(json_txt);

    if(!reader.parse(ifs, root)){
        std:cout << "error Read" << std::endl;
        return 0;
        // "parse fail";
    } else {
        auto &trainParametr = root["train"];
        double learning_rate = trainParametr["learning rate"].asDouble();
        std::cout << "learning rate is " << learning_rate << std::endl;
        ifs.close();
    }
     */
    return 0;
}