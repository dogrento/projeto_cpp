#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "pessoa.h"
#include "principal.h"

class Principal{
private:
    // Os objetos Pessoa estao incluidos (ou agregados) ao obj principal.
    // Conceito de agregaçao forte
    // NOTA* A construtora sem param de cada obj é chamada.
    Pessoa fulano;
    Pessoa Einstein;
    Pessoa Newton;

    Universidade utfpr;
    Universidade princeton; //Einstein - fisica
    Universidade cambridge; // Newton - mat
    
public:
    // Construtora
    Principal();
    // Destrutora; Ao contrario do que pensava, ele serve para 
    // "Destruir" coisas. nao necessariamente destruir o obj em si.
    ~Principal();

    // Metodos
    void exec();
};

#endif