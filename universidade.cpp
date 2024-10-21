#include "universidade.h"

Universidade::Universidade(const char nome[]){
    setUni(nome);
}

Universidade::~Universidade(){}

void Universidade::setUni(const char uniNome[]){
    strcpy(nome, uniNome);
}

char* Universidade::getUni(){
    return nome;
}