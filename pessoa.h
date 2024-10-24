#ifndef PESSOA_H
#define PESSOA_H

#include <string.h>
using namespace std;
#include "universidade.h"
#include "dpto.h"

class Pessoa{
protected:// protected permite herança

  int diaP;
  int mesP;
  int anoP;
  int idadeP;
  char nomeP[30];
  int ID;

public:
  // Construtora com valor default
  // NOTA* nao é possivel definir valor default caso os parametros mais a direita nao estejam com valor default. 
  // Ou seja, colcar os paremetro com default value sempre a direita.
  // Valores default sempre no .h e nao no .cpp
  Pessoa(int dia, int mes, int ano, const char nome[] = "", int id = -1);
  Pessoa(); // Toda classe deve ter construtora sem param.
  ~Pessoa();

  // Metodos
  void init(int dia, int mes, int ano, const char nome[] = "", int id = -1);
  void calcIdade(int diaAtual, int mesAtual, int anoAtual);
  int getIdade(){return idadeP;};
  void setName(const char n[]){strcpy(nomeP, n);};
  char* getName(){return nomeP;};
  void setID(int id){ID = id;};
  int getID(){return ID;};
  void informaInfo();
  // void setUni(Universidade* uni);
  // void setDpto(Dpto* d);
  // void informaUni();
};

#endif