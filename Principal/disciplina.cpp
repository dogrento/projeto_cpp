#include "disciplina.h"

Disciplina::Disciplina(int i, int na, char* ac):
objListAlunos(na,ac){
    id = i;
    dptoFiliado = NULL;

    strcpy(areaConhecimento, ac);
}

Disciplina::~Disciplina()
{
    dptoFiliado = NULL;
}

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

void Disciplina::Inclua_aluno( Aluno* aluno)
{
    objListAlunos.Inclua_aluno(aluno);
}

void Disciplina::Listar_alunos()
{
    objListAlunos.Listar_alunos();
}

void Disciplina::Listar_alunos2()
{
    objListAlunos.Listar_alunos2();
}
