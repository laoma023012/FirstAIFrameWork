//
// Created by mxc on 2020/10/8.
//

#include "LayerBlob.h"

void Blob::_init(const int n, const int c, const int h, const int w, int type) {
    if ( type == TONES ){
        blobData = std::vector<arma::cube>(n, arma::cube(h, w, c, arma::fill::ones));
        return;
    }
    if ( type == TZEROS){
        blobData = std::vector<arma::cube>(n, arma::cube(h, w, c, arma::fill::zeros));
        return;
    }
    if ( type == TDEFAULT){
        blobData = std::vector<arma::cube>(n, arma::cube(h, w, c));
        return;
    }
    if ( type == TRANDU ) {
        for (int i = 0; i < n; i++) {
            blobData.emplace_back(arma::randu<arma::cube>(h, w, c));
        }
        return;
    }
    if ( type == TRANDN ){
        for(int i = 0; i < n; i++){
            blobData.emplace_back(arma::randn<arma::cube>(h,w,c));
        }
        return;
    }
}

Blob::Blob(const int n, const int c, const int h, const int w, int type) {
    _init(n ,c, h, w, type);
}