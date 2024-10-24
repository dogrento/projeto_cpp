#include "professor.h"

Professor::Professor(int dia, int mes, int ano, const char nome[], int id):
Pessoa(dia, mes, ano, nome, id){ // construtora herda de pessoa.
    uniP = nullptr;
    dptoP = nullptr;
}

Professor::Professor(){}

Professor::~Professor(){}

void Professor::informaUni(){
    cout << "   Universidade: " << uniP->getName() << endl; 
}

void Professor::informaDpto(){
    cout << "   Departamento: " << dptoP->getName() << endl; 
}

void Professor::informaInfo(){
    Pessoa::informaInfo();
    cout << "Posição: Professor," << endl;
    informaUni();
    informaDpto();
}