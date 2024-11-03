#include "universidade.h"

Universidade::Universidade():
ID(-1),
uniName("")
{
    for(int i = 0; i < 50; i++){
        dptoP[i] = nullptr;
    }
}

Universidade::~Universidade(){}

void Universidade::informaDptoList(){
    for(int i = 0; i < 50; i++){
        if(dptoP[i] != nullptr){
            dptoP[i]->informaDpto();
        }
    }
}