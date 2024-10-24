#pragma once

#include <string.h>
#include <iostream>
using namespace std;

#include "pessoa.h"
#include "universidade.h"
#include "dpto.h"

class Aluno:public Pessoa{ // Aluno herda de Pessoa
private:
  char ra[7];  
// protected:// protected permite herança
//   Universidade* uniP; // referencia a um objeto associado (Universidade no caso)
//   Dpto* dptoP; // referencia a um objeto associado (Dpto no caso)

public:
  // Construtora com valor default
  // NOTA* nao é possivel definir valor default caso os parametros mais a direita nao estejam com valor default. 
  // Ou seja, colcar os paremetro com default value sempre a direita.
  // Valores default sempre no .h e nao no .cpp
  Aluno(int dia, int mes, int ano, const char nome[] = "");
  Aluno(); // Toda classe deve ter construtora sem param.
  ~Aluno();

  // Metodos
  void setRa(const char ra[]);
  char* getRa();
  // void setUni(Universidade* uni);
  // void setDpto(Dpto* d);
  // void informaUni();
  // void informaDpto();
  void informaInfo();
};