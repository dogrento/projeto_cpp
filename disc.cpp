#include "disc.h"

Disc::Disc(int id, int n, const char ac[]){
    setID(id);
    strcpy(areaConhecimento, ac);
};

void Disc::setDpto(Dpto* d){
    pDptoAssociado = d;
    d->insertDisc(this); // insira *este obj* na lista de departamento associado
    };

Disc::~Disc(){};