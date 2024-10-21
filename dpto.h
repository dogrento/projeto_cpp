#pragma once

#include <string.h>


class Dpto{
    private:
    char dptoName[30];

    public:
    // construtora
    Dpto();
    ~Dpto();

    //metodos
    void setDpto(const char dptoN[]);
    char* getDpto();

    void informaDpto();
};