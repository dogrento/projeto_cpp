#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#include "dpto.h"

class Universidade{
private:
    // char uniName[30];
    int                     ID;
    string                  uniName;
    Dpto                    *dptoP[50];

public:
    // Construtora
    Universidade            ();
    ~Universidade           ();

    // metodo
    void   setName          (string uniN){uniName = uniN;};
    string getName          (){return uniName;};
  
    void   setID            (int id){ID = id;};
    int    getID            (){return ID;};
  
    void   setDptoList      (Dpto *d, int index){dptoP[index] = d;};
    void   informaDptoList  ();
  
    void   salvaUni         (ofstream& f);
};

#endif