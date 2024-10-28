#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

#include <string.h>
#include <iostream>
using namespace std;

#include "dpto.h"

class Universidade{
private:
    // char uniName[30];
    string uniName;
    Dpto *dptoP[50];

public:
// Construtora
    Universidade();
    ~Universidade();

    // metodo
    void setName(string uniN){uniName = uniN;};
    string getName(){return uniName;};

    void setDptoList(Dpto *d, int index){dptoP[index] = d;};
    void informaDptoList();
};

#endif