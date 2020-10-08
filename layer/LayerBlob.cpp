//
// Created by mxc on 2020/10/8.
//

#include "LayerBlob.h"

Blob::Blob(const int n, const int c, const int h, const int w, int type) {
    if ( type == TONES ){
        blobData = std::vector<arma::cube>(n, arma::cube(h, w, c, arma::fill::ones));
    }
    if ( type == TZEROS){
        blobData = std::vector<arma::cube>(n, arma::cube(h, w, c, arma::fill::zeros));
    }
    if ( type == TDEFAULT){
        blobData = std::vector<arma::cube>(n, arma::cube(h, w, c));
    }
    if ( type == TRANDU){}
    if ( type == TRANDN){}
}