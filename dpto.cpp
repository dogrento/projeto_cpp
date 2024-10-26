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
    discList.push_back(pD);
}

void Dpto::listDisc(){
    cout << "Departamento:  " << getName() << endl;

    for(const auto& disc : discList){ // const indica que var nao sera alterada na iteracao, auto tipagem automatica cpp11 &end elemento e colecao
        cout << "\n    " << disc->getName() << endl;
    }
}