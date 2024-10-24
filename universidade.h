#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

#include <string.h>
#include <iostream>
using namespace std;

#include "dpto.h"

class Universidade{
private:
    char uniName[30];
    Dpto *dptoP[50];

public:
// Construtora
    Universidade();
    ~Universidade();

    // metodo
    void setName(const char uniN[]){strcpy(uniName, uniN);};
    char* getName(){return uniName;};

    void setDptoList(Dpto *d, int index){dptoP[index] = d;};
    void informaDptoList();
};

#endif