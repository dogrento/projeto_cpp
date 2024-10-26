#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <iostream>
using namespace std;

#include "professor.h"
#include "aluno.h"
#include "principal.h"
#include "dpto.h"
#include "disc.h"

class Principal{
private:
    // Os objetos derivados de Pessoa estao incluidos (ou agregados) ao obj principal.
    // Conceito de agregaçao forte
    // NOTA* A construtora sem param de cada obj é chamada.
    Professor prof0, prof1, prof2, einstein, newton;
    
    Aluno aluno0, aluno1;

    Universidade utfpr, princeton, cambridge;
    
    Dpto daeln, dpto1, dpto2, fisica, mat;

    Disc daelDisc0, daelDisc1,
        dpto1Disc0, dpto1Disc1, 
        dpto2Disc0, dpto2Disc1,
        fisDisc, matDisc;
    

public:
    // Construtora
    Principal();
    // Destrutora; Ao contrario do que pensava, ele serve para 
    // "Destruir" coisas. nao necessariamente destruir o obj em si.
    ~Principal();

    // Metodos
    void menu();

    void exec();

    void profInit();
    void alunoInit();
    void universidadeInit();
    void dptoInit();
    void discInit();

    void setUniDpto(); // associa dpto a universidade
    void setProfUni(); // associa professor a universidade
    void setProfDpto(); // add professor a dpto
    void setDptoDisc(); // add disciplina ao dpto
    void setAlunoDisc(); // matricula aluno a disciplina
};

#endif