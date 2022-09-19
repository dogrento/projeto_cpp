#include "disciplina.h"

Disciplina::Disciplina(char* ac){
    dptoFiliado = NULL;
    next = NULL;

    strcpy(areaConhecimento, ac);
}

Disciplina::~Disciplina()
{}

void Disciplina::Set_id(int i){
    id = i;
}

int Disciplina::Get_id(){
    return id;
}

void Disciplina::Set_disc(char* n){
    strcpy(nomeDisc, n);
}

char* Disciplina::Get_disc(){
    return nomeDisc;
}

void Disciplina::Set_dpto(Departamento* pd){
    dptoFiliado = pd;
    pd->Set_disciplina(this);
}

Departamento* Disciplina::Get_dpto(){
    return dptoFiliado;
}