#include "pessoa.h"

Pessoa::Pessoa(int dia, int mes, int ano, char nome[]){
  diaP = dia;
  mesP = mes;
  anoP = ano;
  strcpy(nomeP, nome);
  idadeP = 0;
}

void Pessoa::calcIdade(int diaAtual, int mesAtual, int anoAtual){
  idadeP = anoAtual - anoP;

  if(mesAtual < mesP)
    idadeP = idadeP-1;
  else
    if (mesP == mesAtual) {
      if (diaP < diaAtual) {
        idadeP = idadeP-1;
      }
    }
}


int Pessoa::getIdade(){
  return idadeP;
}
