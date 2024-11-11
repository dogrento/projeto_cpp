#pragma once

#include <string.h>
#include <iostream>
#include <list>

using namespace std;

class Universidade; // evita include recursivo. 
class Disc; // evita iclude recursivo.

class Dpto{
    private:
    int           ID;
    string        dptoName;
    Universidade *uniP; // Associacao com uma Universidade
    list<Disc*>   discList;

    public:
    // construtora
    Dpto();
    // Dpto(int id = -1);
    ~Dpto();

    //metodos
    void          setID(int id)               {ID = id;};
    int           getID()const                {return ID;};

    void          setName(const string dptoN) {dptoName = dptoN;};
    const string  getName()const              {return dptoName;};

    void          setUni(Universidade *u)     {uniP = u;};
    Universidade* getUni()const               {return uniP;};

    void          informaDpto()const;
         
    void          insertDisc(Disc* pD);
    void          listDisc();

    void          salvaDpto(ofstream& f);
    Dpto*         recuperaDpto(ifstream& f);
};
