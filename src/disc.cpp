#include "disc.h"

Disc::Disc(int id, int n, const char ac[]){
    setID(id);
    strcpy(areaConhecimento, ac);
};

void Disc::setDpto(Dpto* d){
    cout << "setDpto()-> Associando " <<
     d->getName() << " a " << this->getName() << endl;
     
    pDptoAssociado = d;
    d->insertDisc(this); // insira *este obj* na lista de departamento associado
    };

Disc::~Disc(){};

void Disc::listAlunos(){
    cout << "Alunos matriculados: " << endl;
    if(!alunoList.empty()){
        for(const auto& a : alunoList){
            cout << "   " << a->getName() << endl;
        }
    }else{
        cout << "Nenhum aluno matriculado." << endl;
    }
}

void Disc::informaDpto(){
    cout << "Disciplina pertence ao dpto: " << endl;
    getDpto()->informaDpto();
}

void Disc::informaAC(){
    cout << areaConhecimento << endl;
}

void Disc::informaInfo(){
    informaDpto();
}