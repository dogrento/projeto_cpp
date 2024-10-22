#include "universidade.h"

Universidade::Universidade(){
    for(int i = 0; i < 50; i++){
        dpto[i] = nullptr;
    }
}

Universidade::~Universidade(){}

void Universidade::setUni(const char uniNome[]){
    strcpy(nome, uniNome);
}

char* Universidade::getUni(){
    return nome;
}

void Universidade::setDpto(Dpto *d, int index){
    // agregacao via ptr
    dpto[index] = d;
}

void Universidade::informaDpto(){
    for(int i = 0; i < 50; i++){
        if(dpto[i] != nullptr){
            cout << dpto[i]->getDpto() << endl;
        }
    }
}