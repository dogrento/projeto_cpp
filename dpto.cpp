#include "dpto.h"
#include <iostream>
using std::cout;
using std::endl;

Dpto::Dpto(){
    strcpy(dptoName, "");
}

Dpto::~Dpto(){
}

void Dpto::setDpto(const char dptoN[]){
    strcpy(dptoName, dptoN);
}

char* Dpto::getDpto(){
    return dptoName;
}

void Dpto::informaDpto(){
    cout << "Departamento: " << dptoName << endl;
}