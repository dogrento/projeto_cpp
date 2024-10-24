// #pragma once
#ifndef DPTO_H
#define DPTO_H

#include <string.h>
#include <iostream>
using namespace std;

class Universidade; // evita include recursivo. 

class Dpto{
    private:
    int ID;
    char dptoName[100];
    Universidade *uniP;

    public:
    // construtora
    Dpto();
    Dpto(int id = -1);
    ~Dpto();

    //metodos
    void setID(int id){ID = id;};
    int getID(){return ID;};
    void setName(const char dptoN[]){strcpy(dptoName, dptoN);};
    char* getName(){return dptoName;};
    void setUni(Universidade *u){uniP = u;};

    void informaDpto();
};

#endif