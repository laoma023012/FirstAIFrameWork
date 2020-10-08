//
// Created by mxc on 2020/10/8.
//

#include "readData.h"
#include <fstream>
#include <iostream>
#include <memory>
int ReadData::ReverseInt(int i) {
    unsigned char ch1, ch2, ch3, ch4;
    ch1 = i & 255;
    ch2 = (i >> 8) & 255;
    ch3 = (i >> 16) & 255;
    ch4 = (i >> 24) & 255;
    return ((int)ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
}

void ReadData::readMinistData(std::string path, std::shared_ptr<Blob> &images) {
    std::ifstream file(path, arma::ios::binary);
    if(file.is_open()){
        int magic_number = 0;
        int number_of_images = 0;
        int n_rows = 0;
        int n_cols = 0;
        file.read((char*)&magic_number, sizeof(magic_number));
        magic_number = ReverseInt(magic_number);
        std::cout << "magic_number=" << magic_number << std::endl;
        file.read((char*)&number_of_images, sizeof(number_of_images));
        number_of_images = ReverseInt(number_of_images);
        std::cout << "number_of_images=" << number_of_images << std::endl;
        file.read((char*)&n_rows, sizeof(n_rows));
        n_rows = ReverseInt(n_rows);
        std::cout << "n_rows=" << n_rows << std::endl;
        file.read((char*)&n_cols, sizeof(n_cols));
        n_cols = ReverseInt(n_cols);
        std::cout << "n_cols=" << n_cols << std::endl;

        for (int i = 0; i < number_of_images; ++i)
        {
            for (int h = 0; h < n_rows; ++h)
            {
                for (int w = 0; w < n_cols; ++w)
                {
                    unsigned char temp = 0;
                    file.read((char*)&temp, sizeof(temp));
                    (*images)[i](h, w, 0) = (double)temp / 255;
                }
            }
        }
    }
    else
    {
        std::cout << "no data file found :-(" << std::endl;
    }
}

void ReadData::readMinistLabel(std::string path, std::shared_ptr<Blob> &labels) {
    std::ifstream file(path, arma::ios::binary);
    if (file.is_open())
    {
        int magic_number = 0;
        int number_of_images = 0;
        file.read((char*)&magic_number, sizeof(magic_number));
        magic_number = ReverseInt(magic_number);
        std::cout << "magic_number=" << magic_number << std::endl;
        file.read((char*)&number_of_images, sizeof(number_of_images));
        number_of_images = ReverseInt(number_of_images);
        std::cout << "number_of_Labels=" << number_of_images << std::endl;
        for (int i = 0; i<number_of_images; ++i)
        {
            unsigned char temp = 0;
            file.read((char*)&temp, sizeof(temp));
            (*labels)[i](0, 0, (int)temp) = 1;
        }
    }
    else
    {
        std::cout << "no label file found :-(" << std::endl;
    }
}