#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "pessoa.h"

class Principal{
private:
    Pessoa fulano;
    Pessoa Einstein;
    Pessoa Newton;
    
public:
    // Construtora
    Principal();

    // Metodos
    void exec();
};

#endif