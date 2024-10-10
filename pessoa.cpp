#include "pessoa.h"

Pessoa::Pessoa(int dia, int mes, int ano, const char nome[]){ // C++ exige const char*. Razao: essa variavel é criada apenas durante a chamada da func 
  diaP = dia;
  mesP = mes;
  anoP = ano;
  strcpy(nomeP, nome); // jeito certo; jeito errado -> nomeP = nome. Razao: nesse caso, nomeP receberia o ponteiro da variavel temporaria nome. Ao sair da funcao nomeP seria indeterminado.
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
