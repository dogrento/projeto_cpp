#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#include "dpto.h"
#include "../helpers/myList.h"

class Universidade{
/*
    ATRIBUTOS
*/
private:
    // char uniName[30];
    int                ID;
    string             uniName;
    MyList::DptoList   dptoList;
    // Dpto            *dptoP[50];

/*
    METODOS
*/
public:
    // Construtora/Destrutora
    Universidade    ();
    ~Universidade   ();

    void            setName          (const string uniN){uniName = uniN;};
    string          getName          (){return uniName;};
           
    void            setID            (const int id){ID = id;};
    int             getID            (){return ID;};
           
    void            setDptoList      (Dpto *d){dptoList.insertDpto(d);};
    void            informaDptoList  ();
           
    void            salvaUni         (ofstream& f);
    Universidade*   recuperaUni      (ifstream& f);
};

#endif