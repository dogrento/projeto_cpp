#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <iostream>
using namespace std;

#include "professor.h"
#include "aluno.h"
#include "principal.h"
#include "dpto.h"

class Principal{
private:
    // Os objetos Pessoa estao incluidos (ou agregados) ao obj principal.
    // Conceito de agregaçao forte
    // NOTA* A construtora sem param de cada obj é chamada.
    Professor prof0, prof1, prof2, einstein, Newton;
    Aluno aluno0, aluno1;

    Universidade utfpr, princeton, cambridge;
    
    Dpto daeln, dpto1, dpto2, fisica, mat;
public:
    // Construtora
    Principal();
    // Destrutora; Ao contrario do que pensava, ele serve para 
    // "Destruir" coisas. nao necessariamente destruir o obj em si.
    ~Principal();

    // Metodos
    void exec();
    void profInit();
    void alunoInit();
    void universidadeInit();
    void dptoInit();
    void setUniDpto();
    void setProfUni();
    void setProfDpto();
};

#endif