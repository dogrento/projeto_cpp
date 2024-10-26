#pragma once

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <list>
using namespace std;

#include "dpto.h"
#include "aluno.h"

class Disc{
    // attr
private:
    int ID;
    char name[150];
    char areaConhecimento[150];
    Dpto* pDptoAssociado;
    list <Aluno*> alunoList;

public:
    // construtora / destrutora
    Disc(int id = 0, int n = 0, const char ac[] = "");
    ~Disc();

    // metodos
    void setID(int id)     {ID = id;};
    int getID()            {return ID;};

    void setName(const char n[]) {strcpy(name, n);};
    char* getName()        {return name;};

    void setDpto(Dpto* d);
    Dpto* getDpto()        {return pDptoAssociado;};

    void insertAluno(Aluno* a){alunoList.push_back(a);};
    void listAlunos();

    void informaDpto();
    void informaAC();
    void informaInfo();
};