// #pragma once
#ifndef DPTO_H
#define DPTO_H

#include <string.h>

class Universidade; // evita include recursivo. 

class Dpto{
    private:
    char dptoName[30];
    Universidade *uni;

    public:
    // construtora
    Dpto();
    ~Dpto();

    //metodos
    void setDpto(const char dptoN[]);
    char* getDpto();

    void informaDpto();
    void setUni(Universidade *u);
};

#endif