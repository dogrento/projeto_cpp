#include "dpto.h"
#include "disc.h"

Dpto::Dpto(){
    setID(-1);
    setName("");
    // pDiscPrim = nullptr;
    // pDiscAtual = nullptr;
}


Dpto::~Dpto(){
    // pDiscPrim = nullptr;
    // pDiscAtual = nullptr;
}

void Dpto::informaDpto(){
    cout << "Departamento: " << getID() <<' '<< getName() << endl;
}

void Dpto::insertDisc(Disc* pD){
    cout << "Inserindo " <<
    pD->getName() << " a lista de " << this->getName()<<endl;
    // if(pDiscPrim == nullptr){
    //     cout << "lista vazia..." << endl;
    //     pDiscPrim = pD;
    //     pDiscAtual = pD;
    // }else{
    //     pDiscAtual->pNext = pD;
    //     pDiscAtual = pD;
    // }
    discList.push_back(pD);
}

void Dpto::listDisc(){
    // Disc* pAux;
    // pAux = pDiscPrim;

    cout << "Departamento:  " << getName() << endl;
    // while(pAux != nullptr){
    //     cout << "\n    " << pAux->getName() << endl;
        
    //     pAux = pAux->pNext;
    // }
    for(const auto& disc : discList){
        cout << "\n    " << disc->getName() << endl;
    }
}