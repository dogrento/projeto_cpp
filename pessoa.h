#include <stdio.h>

class Pessoa{
private:
  int diaP;
  int mesP;
  int anoP;
  int idadeP;
  char nomeP[];

public:
  // Construtora
  Pessoa(int dia, int mes, int ano);

  // Metodos
  void calcIdade(int diaAtual, int mesAtual, int anoAtual);
  void getIdade();
};
