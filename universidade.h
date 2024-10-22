#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

#include <string.h>

#include "dpto.h"

class Universidade{
private:
    char nome[100];
    Dpto *dpto[50];

public:
// Construtora
    Universidade();
    ~Universidade();

    // metodo
    void setUni(const char uniNome[]);
    char* getUni();

    void setDpto(Dpto *d, int index);
};

#endif