#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <iostream>
using namespace std;

#include "pessoa.h"
#include "principal.h"
#include "dpto.h"

class Principal{
private:
    // Os objetos Pessoa estao incluidos (ou agregados) ao obj principal.
    // Conceito de agregaçao forte
    // NOTA* A construtora sem param de cada obj é chamada.
    Pessoa fulano0, fulano1, fulano2, Einstein, Newton;

    Universidade utfpr, princeton, cambridge;
    // Universidade princeton; //Einstein - fisica
    // Universidade cambridge; // Newton - mat
    
    Dpto daeln, dpto1, dpto2, fisica, mat;
    // Dpto daeln;
    // Dpto fisica;
    // Dpto mat;
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