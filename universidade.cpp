#include "universidade.h"

Universidade::Universidade():
ID(-1),
uniName("")
{
    for(int i = 0; i < 50; i++){
        dptoP[i] = nullptr;
    }
}

Universidade::~Universidade(){}

void Universidade::informaDptoList(){
    for(int i = 0; i < 50; i++){
        if(dptoP[i] != nullptr){
            dptoP[i]->informaDpto();
        }
    }
}

void Universidade::salvaUni(ofstream& f){
    int nameTamanho = this->getName().size();
    int id = this->getID();
    cout << "Salvando: " << this->getName() << endl;
    f.write((char*) &nameTamanho, sizeof(nameTamanho));
    f.write((char*) &this->getName()[0], nameTamanho);
    f.write((char*) &id, sizeof(id));
}