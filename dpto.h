#pragma once

#include <string.h>
#include <iostream>
#include <list>

using namespace std;

class Universidade; // evita include recursivo. 
class Disc; // evita iclude recursivo.

class Dpto{
    private:
    int ID;
    // char dptoName[100];
    string dptoName;
    Universidade *uniP; // Associacao com uma Universidade
    list<Disc*>discList;

    public:
    // construtora
    Dpto();
    // Dpto(int id = -1);
    ~Dpto();

    //metodos
    void setID(int id){ID = id;};
    int getID(){return ID;};
    void setName(const string dptoN){dptoName = dptoN;};
    const string getName(){return dptoName;};
    void setUni(Universidade *u){uniP = u;};
    Universidade* getUni(){return uniP;};

    void informaDpto();

    void insertDisc(Disc* pD);
    void listDisc();
};
