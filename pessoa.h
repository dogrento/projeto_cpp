#include <stdio.h>
#include <string.h>

class Pessoa{
private:
  int diaP;
  int mesP;
  int anoP;
  int idadeP;
  char nomeP[30];

public:
  // Construtora
  Pessoa(int dia, int mes, int ano, const char nome[]);

  // Metodos
  void calcIdade(int diaAtual, int mesAtual, int anoAtual);
  int getIdade();
};
