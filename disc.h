#pragma once

#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#include "dpto.h"

class Disc{
    // attr
private:
    int ID;
    char name[150];
    char areaConhecimento[150];
    Dpto* pDptoAssociado;

public:
    // construtora / destrutora
    Disc(int id = 0, int n = 0, const char ac[] = "");
    ~Disc();
    Disc* pNext;

    // metodos
    void setID(int id)     {ID = id;};
    int getID()            {return ID;};
    void setName(const char n[]) {strcpy(name, n);};
    char* getName()        {return name;};
    void setDpto(Dpto* d);
    Dpto* getDpto()        {return pDptoAssociado;};

    void informaDpto();
    void informaAC();
    void informaInfo();
};