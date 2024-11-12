#include "aluno.h"

Aluno::Aluno(int dia, int mes, int ano, const char nome[], int id):
Pessoa(dia, mes, ano, nome, id){
    strcpy(RA, "");
}

Aluno::Aluno(){}
Aluno::~Aluno(){}

void Aluno::setRa(const char r[]){
    strcpy(RA, r);
}

void Aluno::informaRA(){
    cout << "   RA: " << getRa() << endl; 
}

void Aluno::informaInfo(){
    Pessoa::informaInfo();
    cout << "Posição: Aluno," << endl;
    informaRA();
}