#include "aluno.h"

Aluno::Aluno(int dia, int mes, int ano, const char nome[], const char r[]):
Pessoa(dia, mes, ano, nome){
    setRa(r);
}

Aluno::Aluno(){}
Aluno::~Aluno(){}

void Aluno::setRa(const char r[]){
    strcpy(ra, r);
}

char* Aluno::getRa(){
    return ra;
}

void Aluno::informaInfo(){
    cout << "Aluno: " << this->nomeP << "RA: " << getRa() << endl;
}