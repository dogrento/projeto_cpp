#include "dpto.h"
#include "disc.h"

Dpto::Dpto(){
    setID(-1);
    setName("");
    pDiscPrim = nullptr;
    pDiscAtual = nullptr;
}

Dpto::Dpto(int id){
    setID(id);
    setName("");
    pDiscPrim = nullptr;
    pDiscAtual = nullptr;
}

Dpto::~Dpto(){
    pDiscPrim = nullptr;
    pDiscAtual = nullptr;
}

void Dpto::informaDpto(){
    cout << "Departamento: " << getID() <<' '<< getName() << endl;
}

void Dpto::insertDisc(Disc* pD){
    if(pDiscPrim == nullptr){
        pDiscPrim = pD;
        pDiscAtual = pD;
    }else{
        pDiscAtual->pNext = pD;
        pDiscAtual = pD;
    }
}

void Dpto::listDisc(){
    Disc* pAux;
    pAux = pDiscPrim;

    while(pAux != nullptr){
        cout << "Disciplina " << pAux->getName() <<
        "pertence ao Dpto " << getName() << endl;
        
        pAux = pAux->pNext;
    }
}