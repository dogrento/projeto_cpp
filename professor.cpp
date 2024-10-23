#include "professor.h"

Professor::Professor(int dia, int mes, int ano, const char nome[]):
Pessoa(dia, mes, ano, nome){ // construtora herda de pessoa.
    uniP = nullptr;
    dptoP = nullptr;
}

Professor::Professor(){}

Professor::~Professor(){}

void Professor::setUniversidade(Universidade* uni){
    uniP = uni;
}

Universidade* Professor::getUni(){
    return uniP;
}

void Professor::setDpto(Dpto* d){
    dptoP = d;
}

Dpto* Professor::getDpto(){
    return dptoP;
}

void Professor::informaUni(){
    cout << "Universidade: " << uniP->getUni() << endl; 
}

void Professor::informaDpto(){
    cout << "Departamento: " << dptoP->getDpto() << endl; 
}

void Professor::informaInfo(){
    cout << "Professor: " << this->nomeP << endl;
    informaUni();
    informaDpto();
}