#include "aluno.h"


Aluno::Aluno(int diaNa, int mesNa, int anoNa, char nome[]):
Pessoa(diaNa, mesNa, anoNa, nome)
{ }

Aluno::Aluno(int i){
    id = i;
    RA = 0;
}

Aluno::~Aluno()
{ }

void Aluno::Set_ra(int ra){
    RA = ra;
}

int Aluno::Get_ra(){
    return RA;
}

void Aluno::Set_departamento(Departamento* dpto){
    dptoFiliado = dpto;
}

Departamento* Aluno::Get_departamento(){
    return dptoFiliado;
}

void Aluno::Set_id(int i){
    id = i;
}

int Aluno::Get_id(){
    return id;
}