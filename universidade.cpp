#include "universidade.h"

Universidade::Universidade(){
    dpto = nullptr;
}

Universidade::~Universidade(){}

void Universidade::setUni(const char uniNome[]){
    strcpy(nome, uniNome);
}

char* Universidade::getUni(){
    return nome;
}

void Universidade::setDpto(Dpto *d){
    // agregacao via ptr
    dpto = d;
}