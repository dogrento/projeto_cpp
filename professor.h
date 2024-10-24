// Classe Professor herda de Pessoa
#pragma once

#include <string.h>
#include <iostream>
using namespace std;

#include "universidade.h"
#include "dpto.h"
#include "pessoa.h"

class Professor:public Pessoa{ // Professor herda de Pessoa
private: 
  Universidade* uniP; // referencia a um objeto associado (Universidade no caso)
  Dpto* dptoP; // referencia a um objeto associado (Dpto no caso)

public:
  // Construtora com valor default
  // NOTA* nao é possivel definir valor default caso os parametros mais a direita nao estejam com valor default. 
  // Ou seja, colcar os paremetro com default value sempre a direita.
  // Valores default sempre no .h e nao no .cpp
  Professor(int dia, int mes, int ano, const char nome[] = "", int id = -1);
  Professor(); // Toda classe deve ter construtora sem param.
  ~Professor();

  // Metodos
//   void init(int dia, int mes, int ano, const char nome[] = "");
  void setUni(Universidade* uni){uniP = uni;};
  Universidade* getUni(){return uniP;};
  void setName(Dpto* d){dptoP = d;};
  Dpto* getName(){return dptoP;};
  void informaUni();
  void informaDpto();
  void informaInfo();
};