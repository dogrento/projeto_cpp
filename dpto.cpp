#include "dpto.h"

Dpto::Dpto(){
    setID(-1);
    setName("");
}

Dpto::Dpto(int id){
    setID(id);
    setName("");
}

Dpto::~Dpto(){
}

void Dpto::informaDpto(){
    cout << "Departamento: " << getID() <<' '<< getName() << endl;
}