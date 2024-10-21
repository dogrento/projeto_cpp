#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

#include <string.h>

#include "dpto.h"

class Universidade{
private:
    char nome[100];
    Dpto *dpto;

public:
// Construtora
    Universidade(const char nome[] = "");
    ~Universidade();

    // metodo
    void setUni(const char uniNome[]);
    char* getUni();

};

#endif