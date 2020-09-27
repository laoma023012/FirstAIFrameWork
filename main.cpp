#include <iostream>
#include <armadillo>
#include "src/TestHello.h"
#include "json/json.h"
#include <string>
#include <fstream>
using namespace std;
//using namespace Json;
using namespace arma;
void testJSON(){
    //TestHello testArmadillo = TestHello();
    //testArmadillo.testHelloWorld();
    //std::cout << "Hello, World!" << std::endl;
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
    ifstream ifs;
    string json_txt = "../networkDefine/layerDefine.json";
    ifs.open(json_txt);
    Json::Value root;
    Json::Reader reader;
    if(!reader.parse(ifs, root)){
        std:cout << "error Read" << std::endl;
        // "parse fail";
    } else {
        auto &trainParametr = root["train"];
        double learning_rate = trainParametr["learning rate"].asDouble();
        std::cout << learning_rate << std::endl;
        sleep(1);
    }
    //testJSON();

    return 0;
}