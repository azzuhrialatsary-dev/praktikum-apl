#ifndef VALIDASI_H
#define VALIDASI_H

#include <stdexcept>
#include <string>
using namespace std;

void cekAngka(int x){
    if(x < 0){
        throw invalid_argument("Input tidak boleh negatif!");
    }
}

void cekKosong(string s){
    if(s.empty()){
        throw runtime_error("Input tidak boleh kosong!");
    }
}

#endif