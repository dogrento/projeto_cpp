#ifndef PESSOA_H
#define PESSOA_H

#include <string.h>
#include "universidade.h"
#include "dpto.h"

class Pessoa{
protected:// protected permite herança

  int diaP;
  int mesP;
  int anoP;
  int idadeP;
  char nomeP[30];
  // Universidade* uniP; // referencia a um objeto associado (Universidade no caso)
  // Dpto* dptoP; // referencia a um objeto associado (Dpto no caso)

public:
  // Construtora com valor default
  // NOTA* nao é possivel definir valor default caso os parametros mais a direita nao estejam com valor default. 
  // Ou seja, colcar os paremetro com default value sempre a direita.
  // Valores default sempre no .h e nao no .cpp
  Pessoa(int dia, int mes, int ano, const char nome[] = "");
  Pessoa(); // Toda classe deve ter construtora sem param.
  ~Pessoa();

  // Metodos
  void init(int dia, int mes, int ano, const char nome[] = "");
  void calcIdade(int diaAtual, int mesAtual, int anoAtual);
  int getIdade();
  // void setUniversidade(Universidade* uni);
  // void setDpto(Dpto* d);
  // void informaUni();
  // void informaInfo();
};

#endif